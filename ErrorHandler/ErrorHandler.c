#include"ErrorHandler.h"
#include"Windows.h"
void ErrorHandler(char error){
	switch(error){
		case 1:
		{
			MessageBox(NULL,"Not found file",NULL,MB_OK);
			break;
		}
	}
}