#include<stdio.h>
#include<malloc.h>
#include"statistic.h"
char clean(const char* filename) {
  FILE*file;
  fopen_s(&file, filename, "w");
  if (!file) {
    return 1;
  }
  int size = 0;
  fwrite(&size, 4, 1, file);
  fclose(file);
  return 0;
}
char SaveStatistic(char* savedata, const char* filename) {
  FILE* file;
  fopen_s(&file, filename, "r+");
  if (!file) {
    return 1;
  }

  int old_size;
  fread(&old_size, 4, 1, file);

  int size_savedata = 0;
  while (1) {
    if (savedata[size_savedata] == 0) {
      break;
    }
    size_savedata++;
  }

  int new_size = old_size + size_savedata;
  fseek(file, 0, SEEK_SET);
  fwrite(&new_size, 4, 1, file);

  fseek(file, 4 + old_size, SEEK_SET);
  fwrite(savedata, 1, size_savedata, file);

  fclose(file);
  return 0;
}
char* GetStatistic(const char* filename) {
  FILE* file;
  fopen_s(&file, filename, "r");
  if (file==NULL) {
    return NULL;
  }
  int size;
  fread(&size, 4, 1, file);
  char* data = (char*)malloc(size+1);
  data[size] = 0;
  fread(data, 1, size, file);
  fclose(file);
  return data;
}