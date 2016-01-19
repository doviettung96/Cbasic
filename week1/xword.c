#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void main(int argc, char* argv[]){
  char word[] = "replicate";
  int i;
  int x;
  float y;
  
  if(argc != 4)
    printf("Wrong number of arguments. The program now terminates\n");
  else
    {
      y = atof(argv[3]);
      x = (int)y;
      if(y - x != 0 || x == 0)
        printf("The duplicate time must be a integer greater than 0\n");
      else
        {
        if(strcmp(argv[1], word) == 0)
          for(i = 0; i < x; ++i)
            printf("%s",argv[2]);
        printf("\n");
        }
    }
}
