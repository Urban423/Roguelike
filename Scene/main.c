#include "LevelGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{ 
	srand(time(NULL));
	GenerateLevel(100, 28, 13);
	return 0;
}