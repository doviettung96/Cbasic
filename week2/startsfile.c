#include <stdio.h>
#include <string.h>



void main(int argc, char* argv[]){
  FILE* f1;
  FILE* f2;
  int c;
  char* syntax = "syntax";
  char* m1 = "r";
  char* m2 = "w+";
  int count[128];
  int i;
  
  for(i = 0; i < 128; ++i)
    count[i] = 0;
  
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
               count[c]++;
           }
      for(i = 0; i < 128; ++i)
        if(count[i] != 0)
          fprintf(f2, "The character \"%2c\": %4d times\n",i, count[i]);
    }
  fclose(f1);
  fclose(f2);
}

