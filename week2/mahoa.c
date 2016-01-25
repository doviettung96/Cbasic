#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *a, int distance);

void main(int argc, char* argv[]){
  FILE* f1;
  FILE* f2;
  int distance;
  char c[1000];
  char* syntax1 = "en";
  char* syntax2 = "de";
  char* m1 = "r";
  char* m2 = "w";
  int i = 0;
  
  distance = atoi(argv[3]);
  
  if((strcmp(argv[1], syntax1) != 0 && strcmp(argv[1], syntax2) != 0) || argc != 4  )
    printf("Wrong syntax. The program now will be terminated\n");
  else
    {
      if((f1 = fopen(argv[2], m1)) == NULL)
        printf("Can't open file %s\n",argv[2]);
         else
           {
             while( (c[i] = fgetc(f1)) != EOF)
               {
               if(strcmp(argv[1], syntax1) == 0)
                 encrypt(c + i, distance);
               else
                 if(strcmp(argv[1], syntax2) == 0)
                   encrypt(c + i, -distance);
               ++i;
               }
           }
    }

  fclose(f1);  
  f2 = fopen(argv[2], m2);
  fprintf(f2, "%s",c);
  
  fclose(f2);
}

void encrypt(char* a, int distance)
{ 
        if(*a >= 'A' && *a <= 'Z')
          if(*a + distance > 'Z')
            *a -= (26 - distance);
          else
            if(*a + distance < 'A')
              *a += (26 + distance);
            else
              *a += distance;
        else
          if(*a >= 'a' && *a <= 'z')
            if(*a + distance > 'z')
              *a -= (26 - distance);
            else
              if(*a + distance < 'a')
                *a += (26 + distance);
              else
                *a += distance;
 
}
