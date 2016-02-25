#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv)
{
  int max;
  max = atoi(argv[2]);
    
  FILE* fptr1;
  char buff[max + 1];
  int num;
    
  if((fptr1 = fopen(argv[1], "rb")) == NULL)
    printf("Can not open the file %s\n", argv[1]);
  else
    {
      num = fread(buff, sizeof(char), max, fptr1);
      buff[num * sizeof(char)] = '\0';
      printf("%s\n", buff);
    }
  fclose(fptr1);
}
