#include <stdio.h>
#include <string.h>



void main(int argc, char* argv[]){
  FILE* f1;
  FILE* f2;
  int c;
  char* syntax = "mycp";
  char* m1 = "r";
  char* m2 = "w+";
  int i = 0;
  
  if(strcmp(argv[1], syntax) != 0 || argc != 4)
    printf("Wrong syntax. The program now will be terminated\n");
  else
    {
      if((f1 = fopen(argv[2], m1)) == NULL)
        printf("Can't open file %s\n",argv[2]);
      else
         if((f2 = fopen(argv[3], m2)) == NULL)
           printf("Can't open file %s\n",argv[3]);
         else
           {
             while( (c = fgetc(f1)) != EOF)
        {
          fputc(c, f2);
          putchar(c);
            }
           }
    }
  fclose(f1);
  fclose(f2);
}

