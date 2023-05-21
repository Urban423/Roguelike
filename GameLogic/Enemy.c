#include "Enemy.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
includeTime
includeInput

#undef T
#define T Enemy

template(T, functiontable) template(T, table) = {
	template(T, constructor),
	template(T, Start),
	template(T, Update),
	template(T, OnTriggerStay)
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
}

void template(T, Start)(T *this)
{
	this->walkSpeed = 6.3f;
}


/*
vector find_path(int* real_map, int lenght, int height,int index_begin,int index_end) {
    vector result;
    int temp;
    int flag;
    int* path;
    int len_path = 1;
    int n = 1;
    result.size = 0;
    result.path = NULL;
    int* map = (int*)malloc(lenght * height * 4);
    for (int i = 0; i < lenght * height; i++) {
        map[i]=real_map[i];
    }
    int index=index_end;
    map[index_begin] = -1;
    if (index_begin >= lenght) {  
        if (map[index_begin - lenght] == 0) {
            map[index_begin - lenght] = len_path;
        }
    }
    if (index_begin < lenght*(height-1)) {
        if (map[index_begin + lenght] == 0) {
            map[index_begin + lenght] = len_path;
        }
    }//вниз
    if ((index_begin + 1)%lenght != 0) {
        if (map[index_begin + 1] == 0) {
            map[index_begin + 1] = len_path;
        }
    }
    if (index_begin % lenght != 0) {
        if (map[index_begin - 1] == 0) {
            map[index_begin - 1] = len_path;
        }
    }
    while (map[index_end] == 0) {
        len_path++;
        flag = 0;
        for (int i = 0; i < lenght*height; i++) {
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
            return result;
        }
    }
    result.size = len_path;
    path = (int*)malloc(len_path * 4);
    path[0] = index_end;
    while (len_path != 1) {
        len_path = len_path - 1;
        if (index >= lenght) {
            if (map[index-lenght] == len_path) {
                index-=lenght;
                path[n++] = index;
            }
        }
        if (index < lenght * (height - 1)) {
            if (map[index+lenght] == len_path) {
                index+=lenght;
                path[n++] = index;
            }
        }
        if ((index+1)%lenght!=0) {
            if (map[index+1] == len_path) {
                index+=1;
                path[n++] = index;
            }
        }
        if (index % lenght != 0) {
            if (map[index-1] == len_path) {
                index-=1;
                path[n++] = index;
            }
        }
    }
    for (int i = 0, j = result.size - 1; i < j; i++, j--) {
        temp = path[i];
        path[i] = path[j];
        path[j] = temp;
    }
    result.path = path;
    free(map);
    return result;
}
*/


void template(T, Update)(T *this)
{
	Vector2 tagerDir = {
		this->player->position.x - this->inherited_class.object->transform.position.x,
		this->player->position.y - this->inherited_class.object->transform.position.y
	};
	
	if(lengthSquare(tagerDir) < 150){
		this->inherited_class.object->transform.position = MoveTowards(
		this->inherited_class.object->transform.position,
		this->player->position,
		Time.deltaTime * this->walkSpeed);
	}
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	Player* player;
	TEMPLATE(GetComponent, Player)(entered, &player);
	if(player != NULL)
	{
		Kill(player);
	}
}