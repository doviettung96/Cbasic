#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void main(int argc, char* argv[]){
  FILE* f1;
 
  int c;
  char* syntax = "cat";
  char* m1 = "r";
  char* mod = "-p";
  int i = 0;
  int num;

  num = atoi(argv[4]);
  
  
  if(strcmp(argv[1], syntax) != 0 || argc != 3 && argc != 5)
    printf("Wrong syntax. The program now will be terminated\n");
  else
    {
      if((f1 = fopen(argv[2], m1)) == NULL)
        printf("Can't open file %s\n",argv[2]);
      else
        if (argc == 3)
          while( (c = fgetc(f1)) != EOF)
            putchar(c);
        else
          if (strcmp(argv[3],mod) == 0)
            while ((c = fgetc(f1)) != EOF)
              {
                if(c == '\n')
                  i++;
                if(i >= num*25 - 25 && i < 25*num)
                  putchar(c); 
              }
    }
  fclose(f1);
}

