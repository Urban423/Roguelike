#include "LevelGenerator.h"
#include "Vector2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define abs(x)  ( ( (x) < 0) ? -(x) : (x) )

const unsigned int MIN_LEAF_SIZE = 4;
	
typedef struct Rectangle
{
	int width, height;
	int x, y;
}Rectangle;

typedef struct RectangleMassive
{
	int size;
	Rectangle* list;
}RectangleMassive;

void push(RectangleMassive* list, Rectangle new)
{
	Rectangle* new_list = (Rectangle*)malloc(sizeof(Rectangle) * (list->size + 1));
	for(int i = 0; i < list->size; i++)
	{
		new_list[i] = list->list[i];
	}
	new_list[list->size] = new;
	
	if(list->list != 0)
	{
		free(list->list);
	}
	list->list = new_list;
	list->size++;
}

Rectangle new_Rectangle(int X, int Y, int Width, int Height)
{
	Rectangle rect;
	rect.x = X;
	rect.y = Y;
	rect.width = Width;
	rect.height = Height;
	return rect;
}

void printRectangle(Buffer* buffer, Rectangle rect)
{
	for(unsigned int j = 0; j < rect.height; j++)
	{
		for(unsigned int i = 0; i < rect.width; i++)
		{
			buffer->buffer[(j + rect.y) * (buffer->width) + (i + rect.x)] = '#';
		}
	}
}

typedef struct Leaf
{
	int x, y, width, height; // положение и размер этого листа

	struct Leaf* leftChild; // левый дочерний Leaf нашего листа
	struct Leaf* rightChild; // правый дочерний Leaf нашего листа
	Rectangle room; // комната, находящаяся внутри листа
	//struct Leaf halls:Vector; // коридоры, соединяющие этот лист с другими листьями
	RectangleMassive halls;
}Leaf;

Leaf* new_Leaf(int X, int Y, int Width, int Height)
{
	Leaf* _leafs = (Leaf*)malloc(sizeof(Leaf));
	// инициализация листа
	_leafs->halls.size = 0;
	_leafs->halls.list = 0;
	_leafs->x = X;
	_leafs->y = Y;
	_leafs->width = Width;
	_leafs->height = Height;
	_leafs->leftChild = 0;
	_leafs->rightChild = 0;
	return _leafs;
}

int RandomRange(int a, int b)
{
	int delta = abs(a - b) + 1;
	return MIN(a, b) + (rand() % delta);
}

float RandomPercent()
{
	return (float)(rand() % 100) / 100;
}

char split(Leaf* this)
{
	// начинаем разрезать лист на два дочерних листа
	if (this->leftChild != 0 || this->rightChild != 0)
		return 0; // мы уже его разрезали! прекращаем!

	// определяем направление разрезания
	// если ширина более чем на 25% больше высоты, то разрезаем вертикально
	// если высота более чем на 25% больше ширины, то разрезаем горизонтально
	// иначе выбираем направление разрезания случайным образом
	char splitH =  RandomPercent() > 0.5;
	if (this->width > this->height && this->width / this->height >= 1.25)
	{
		splitH = 0;
	}
	else if (this->height > this->width && this->height / this->width >= 1.25)
	{
		splitH = 1;
	}

	int max = (splitH ? this->height : this->width) - MIN_LEAF_SIZE; // определяем максимальную высоту или ширину
	if (max <= MIN_LEAF_SIZE)
	{
		return 0; // область слишком мала, больше её делить нельзя...
	}

	int split = RandomRange(MIN_LEAF_SIZE, max); // определяемся, где будем разрезать

	// создаём левый и правый дочерние листы на основании направления разрезания
	if (splitH)
	{
		this->leftChild = new_Leaf(this->x, this->y, this->width, split);
		this->rightChild = new_Leaf(this->x, this->y + split, this->width, this->height - split);
	}
	else
	{
		this->leftChild = new_Leaf(this->x, this->y, split, this->height);
		this->rightChild = new_Leaf(this->x + split, this->y, this->width - split, this->height);
	}
	return 1;
}

void createHall(Leaf* this, Rectangle l, Rectangle r)
{
	this->halls.size = 0;
	this->halls.list = 0;

	Vector2 point1 = newVector2(
	RandomRange(l.x + 1, l.x + l.width - 2),
	RandomRange(l.y + 1, l.y + l.height - 2));
	
	Vector2 point2 = newVector2(
	RandomRange(r.x + 1, r.x + r.width - 2),
	RandomRange(r.y + 1, r.y + r.height - 2));

	if(point1.x > point2.x)
	{
		swap_Vector2(&point1, &point2);
	}
	int w = point2.x - point1.x;
	int h = point2.y - point1.y;

	if(w == 0)
	{
		if(h < 0)
		{
			push(&this->halls, new_Rectangle(point2.x, point2.y, 1, abs(h)));
		}
		else
		{
			push(&this->halls, new_Rectangle(point1.x, point1.y, 1, abs(h)));
		}
	}
	else
	{
		if(h == 0)
		{
			push(&this->halls, new_Rectangle(point1.x, point2.y, abs(w), 1));
			return;
		}
		
		push(&this->halls, new_Rectangle(point1.x, point1.y, abs(w), 1));
		if(h < 0)
		{
			push(&this->halls, new_Rectangle(point1.x + abs(w) - 1, point2.y, 1, abs(h)));
			return;
		}
		push(&this->halls, new_Rectangle(point1.x + abs(w) - 1, point1.y, 1, abs(h)));
	}
}

Rectangle getRoom(Leaf* this)
{
	// итеративно проходим весь путь по этим листьям, чтобы найти комнату, если она существует.
	if (this->leftChild == 0 || this->rightChild == 0)
	{
		return this->room;
	}
	else
	{
		Rectangle lRoom;
		Rectangle rRoom;
		if (this->leftChild != 0)
		{
			lRoom = getRoom(this->leftChild);
		}
		if (this->rightChild != 0)
		{
			rRoom = getRoom(this->rightChild);
		}
		
		if (RandomPercent() > 0.5f)
		{
			return lRoom;
		}
		else
		{
			return rRoom;
		}
	}
}

void createRooms(Leaf* this)
{
	// эта функция генерирует все комнаты и коридоры для этого листа и всех его дочерних листьев.
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		// этот лист был разрезан, поэтому переходим к его дочерним листьям
		if (this->leftChild != 0)
		{
			createRooms(this->leftChild);
		}
		if (this->rightChild != 0)
		{
			createRooms(this->rightChild);
		}
		if (this->leftChild != 0 && this->rightChild != 0)
		{
			Rectangle a = getRoom(this->leftChild);
			Rectangle b = getRoom(this->rightChild);
			//printf("%d %d\n", a.x, a.y);
			//createHall(this, a, b);
		}
	}
	else
	{
		// этот лист готов к созданию комнаты
		Vector2 roomSize;
		Vector2 roomPos;
		// размер комнаты может находиться в промежутке от 3 x 3 тайла до размера листа - 2.
		roomSize = newVector2(RandomRange(3, this->width - 2), RandomRange(3, this->height - 2));
		if(roomSize.x < 3) { roomSize.x = 3; }
		if(roomSize.y < 3) { roomSize.y = 3; }
		
		// располагаем комнату внутри листа, но не помещаем её прямо 
		// рядом со стороной листа (иначе комнаты сольются)
		roomPos = newVector2(
		RandomRange(1, this->width - roomSize.x - 1), 
		RandomRange(1, this->height - roomSize.y - 1));
		
		this->room = new_Rectangle(
		this->x + roomPos.x, 
		this->y + roomPos.y,
		roomSize.x,
		roomSize.y);
	}
}

void createHalls(Leaf* this)
{
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		if (this->leftChild != 0)
		{
			createHalls(this->leftChild);
		}
		if (this->rightChild != 0)
		{
			createHalls(this->rightChild);
		}
		if (this->leftChild != 0 && this->rightChild != 0)
		{
			Rectangle a = getRoom(this->leftChild);
			Rectangle b = getRoom(this->rightChild);
			createHall(this, a, b);
		}
	}
}

void createLeafs(Leaf* this)
{
	const unsigned int MAX_LEAF_SIZE = 20;
	
	if (this->leftChild != 0 || this->rightChild != 0) // если лист ещё не разрезан...
	{
		return;
	}
	
	// если этот лист слишком велик, или есть вероятность 75%...
	if (this->width > MAX_LEAF_SIZE || this->height > MAX_LEAF_SIZE || RandomPercent() > 0.25)
	{
		if (split(this))
		{
			createLeafs(this->leftChild);
			createLeafs(this->rightChild);
		}
	}
}

void drawLeafs(Buffer* buffer, Leaf* this)
{
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		if (this->leftChild != 0)
		{
			drawLeafs(buffer, this->leftChild);
		}
		if (this->rightChild != 0)
		{
			drawLeafs(buffer, this->rightChild);
		}
		for(int i = 0; i < this->halls.size; i++)
		{
			//printf("%d ", this->halls.list[i].x);
			//printf("%d \n", this->halls.list[i].y);
			printRectangle(buffer, this->halls.list[i]);
		}
	}
	else{
		printRectangle(buffer, this->room);
	}
}

int selectSpawn(Buffer* buffer, Leaf* this, char str, char clear, char new)
{
	if (this->leftChild != 0)
	{
		selectSpawn(buffer, this->leftChild, str, clear, new);
	}
	else{
		int rand_x = this->room.x + RandomRange(0, this->room.width - 1);
		int rand_y = this->room.y + RandomRange(0, this->room.height - 1);
		
		buffer->buffer[rand_y * buffer->width + rand_x] = str;
		int index = 0;
		for(int y = -5; y < 5; y++)
		{
			index = (y + rand_y) * buffer->width + rand_x - 5;
			for(int x = -5; x < 5;x++)
			{
				if(index > -1 && index <buffer->width * buffer->height)
				{
					if(buffer->buffer[index] == clear)
					{
						buffer->buffer[index] = new;
					}
				}
				index++;
			}
		}
	}
	return 0;
}

int find_path(int* real_map, int lenght, int height) {
    int index_begin=-1;
    for (int i = 0; i < height; i++) 
	{
        for (int j = 0; j < lenght; j++) 
		{
            if (real_map[i * lenght + j] == 'p') 
			{
                index_begin = i * lenght + j;
                break;
            }
        }
        if (index_begin != -1) {
            break;
        }
    }
    int temp;
    int flag=1;
    int len_path = 1;
    int n = 1;
    int* map = (int*)malloc(lenght * height * 4);
	if(map == 0){ return 0;}
    for (int i = 0; i < lenght * height; i++) {
        if (real_map[i] == ' ') {
            map[i] = -1;
        }
        else {
            map[i] = 0;
        }
    }
    map[index_begin] = -1;
    if (index_begin >= lenght) {
        if (map[index_begin - lenght] == 0) {
            map[index_begin - lenght] = len_path;
        }
    }
    if (index_begin < lenght * (height - 1)) {
        if (map[index_begin + lenght] == 0) {
            map[index_begin + lenght] = len_path;
        }
    }
    if ((index_begin + 1) % lenght != 0) {
        if (map[index_begin + 1] == 0) {
            map[index_begin + 1] = len_path;
        }
    }
    if (index_begin % lenght != 0) {
        if (map[index_begin - 1] == 0) {
            map[index_begin - 1] = len_path;
        }
    }
    while (flag) {
        len_path++;
        flag = 0;
        for (int i = 0; i < lenght * height; i++) {
            if (map[i] == len_path - 1) {
                if (i >= lenght) {
                    if (map[i - lenght] == 0) {
                        map[i - lenght] = len_path;
                        flag = 1;
                    }
                }
                if (i < lenght * (height - 1)) {
                    if (map[i + lenght] == 0) {
                        map[i + lenght] = len_path;
                        flag = 1;
                    }
                }
                if ((i + 1) % lenght != 0) {
                    if (map[i + 1] == 0) {
                        map[i + 1] = len_path;
                        flag = 1;
                    }
                }
                if (i % lenght != 0) {
                    if (map[i - 1] == 0) {
                        map[i - 1] = len_path;
                        flag = 1;
                    }
                }

            }
        }
        if (flag == 0) {
            break;
        }
    }
	
    int index_end = 0;
    for (int i = 0; i < height; i++)
	{
        for (int j = 0; j < lenght; j++)
		{
            if (map[lenght * i + j] > map[index_end])
			{
                index_end = lenght * i + j;
            }
        }
    }
	free(map);
    return index_end;
}


Buffer new_Buffer(unsigned int width, unsigned int height)
{
	Buffer buffer;
	buffer.height = height;
	buffer.width = width;
	buffer.buffer = (int*)malloc(width * height * sizeof(int));
	for(int i = 0; i < height * width; i++)
	{
		buffer.buffer[i] = ' ';
	}
	return buffer;
}

void DrawBuffer(Buffer* buffer)
{
	int index = 0;
	for(int y = buffer->height - 1; y > -1; y--)
	{
		for(int x = 0; x < buffer->width; x++)
		{
			printf("%c ", buffer->buffer[y * buffer->width + x]);
			index++;
		}
		printf("\n");
	}
}

int generateStructInEveryLevel(Buffer* buffer, Leaf* this, char str, float chance, int offset)
{
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		if (this->leftChild != 0)
		{
			generateStructInEveryLevel(buffer, this->leftChild, str, chance, offset);
		}
		if (this->rightChild != 0)
		{
			generateStructInEveryLevel(buffer, this->rightChild, str, chance, offset);
		}
	}
	else{
		int rand_x = this->room.x + RandomRange(offset, this->room.width - 1 - offset);
		int rand_y = this->room.y + RandomRange(offset, this->room.height - 1 - offset);
		//printf("%d %d: %d\n", 0, this->room.height, rand_y - this->room.y);
		
		if(RandomRange(0, 1) < chance)
		{
			buffer->buffer[rand_y * buffer->width + rand_x] = str;
		}
	}
	return 0;
}

Leaf* findRootWithElement(Buffer* buffer, Leaf* this, char Element)
{
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		Leaf* res = NULL;
		if (this->leftChild != 0)
		{
			res = findRootWithElement(buffer, this->leftChild, Element);
		}
		if (res == NULL && this->rightChild != 0)
		{
			res = findRootWithElement(buffer, this->rightChild, Element);
		}
		return res;
	}
	else{
		for(int y = 0; y < this->room.height; y++)
		{
			for(int x = 0; x < this->room.width; x++)
			{
				if(buffer->buffer[(this->room.y + y) * buffer->width + this->room.x + x] == Element)
				{
					return this;
				}
			}
		}
	}
	return NULL;
}


int generateDoorsInRoom(Buffer* buffer, Leaf* this, char str, char Ignore)
{
	int index = 0;
	for(int y = -1; y < this->room.height + 1; y++)
	{
		index = (this->room.y + y) * buffer->width + this->room.x -1;
		for(int x = -1; x < this->room.width + 1; x++)
		{
			if(index < 0 || index > buffer->height * buffer->width)
			{
				index++;
				continue;
			}
			if(y > -1 && y < this->room.height && x > -1 && x < this->room.width)
			{
				index++;
				continue;
			}
			if(buffer->buffer[index] != Ignore)
			{
				buffer->buffer[index] = str;
			}
			index++;
		}
	}
	return 0;
}

int generateElementInRandomRoom(Buffer* buffer, Leaf* this, Leaf* impossibleRoom1, Leaf* impossibleRoom2, char str, char offset)
{
	if (this->leftChild != 0 || this->rightChild != 0)
	{
		char leftL = this->leftChild != 0  && this->leftChild != impossibleRoom1 && this->leftChild != impossibleRoom2;
		char leftR = this->leftChild != 0  && this->leftChild != impossibleRoom1 && this->leftChild != impossibleRoom2;
		float r = RandomRange(0, 1);
		
		if ((leftL && r < 0.5f) || (leftL && leftR == 0))
		{
			generateElementInRandomRoom(buffer, this->leftChild, impossibleRoom1, impossibleRoom2, str, offset);
		}
		else
		{
			generateElementInRandomRoom(buffer, this->rightChild, impossibleRoom1, impossibleRoom2, str, offset);
		}
	}
	else{
		int rand_x = this->room.x + RandomRange(offset, this->room.width - 1 - offset);
		int rand_y = this->room.y + RandomRange(offset, this->room.height - 1 - offset);
		
		buffer->buffer[rand_y * buffer->width + rand_x] = str;
	}
	return 0;
}

Buffer GenerateLevel(unsigned int width, unsigned int height, int seed)
{
	srand(seed);
	// сначала создаём лист, который будет "корнем" для всех остальных листьев.
	Leaf* root = new_Leaf(0, 0, width, height);
	createLeafs(root);
	createRooms(root);
	
	Buffer buffer = new_Buffer(width, height);
	createHalls(root);
	drawLeafs(&buffer, root);
	
	generateStructInEveryLevel(&buffer, root, ' ', 2, 1);
	generateStructInEveryLevel(&buffer, root, ' ', 2, 1);
	generateStructInEveryLevel(&buffer, root, 'c', 2, 0);
	generateStructInEveryLevel(&buffer, root, 'o', 0.6f, 1);
	generateStructInEveryLevel(&buffer, root, 'k', 0.2f, 0);
	generateStructInEveryLevel(&buffer, root, 'o', 0.6f, 1);
	generateStructInEveryLevel(&buffer, root, 'o', 0.6f, 1);
	generateStructInEveryLevel(&buffer, root, 'o', 0.6f, 1);
	
	
	selectSpawn(&buffer, root, 'p', 'k', 'c');
	int index = find_path(buffer.buffer, buffer.width, buffer.height);
	buffer.buffer[index] = 'e';
	
	Leaf* withPlayer = findRootWithElement(&buffer, root, 'p');
	Leaf* withExit = findRootWithElement(&buffer, root, 'e');
	if(withExit != NULL)
	{
		generateDoorsInRoom(&buffer, withExit, 'd', ' ');
	}
	generateElementInRandomRoom(&buffer, root, withPlayer, withExit, '-', 0);
	
	
	
	DrawBuffer(&buffer);
	
	return buffer;
}