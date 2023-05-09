#include"teststatistic.h"
#include"statistic.h"

char testSaveStatistic(){
	const char* text = "12345";
	clean("test.txt");
	SaveStatistic((char*)text,"test.txt");
	FILE*file1;
	FILE*file2;
	fopen_s(&file1, "test.txt", "r");
	fopen_s(&file2, "test1.txt", "r");
	char x1;
	char x2;
	while (!feof( file1 )){
		fread(&x1, 1, 1, file1);
		fread(&x2, 1, 1, file2);
		if(x1!=x2){
			fclose(file1);
			fclose(file2);
			return 1;
		}
	}
	fclose(file1);
	fclose(file2);
	return 0;
}
char testGetStatistic(){
	char*data=GetStatistic("test.txt");
	const char* text = "12345";
	int index=0;
	while (data[index]!=0)
	{
		if (data[index]!=text[index]){
			return 1;
		}
		index++;
	}
	return 0;
}