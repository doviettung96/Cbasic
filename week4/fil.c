#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define max 10
void main(int argc, char** argv){
  char list[max][10] = {"fuck", "bitch", "sex", "porn", "naked","cock", "suck","scum","shit","damn"};
  FILE* f;
  int count = 0;
  char *p = NULL;
  char c;
  
  if(argc != 3)
    {
      printf("Wrong syntax!\n");
      exit(1);
    }
  else
    if((f = fopen(argv[1], "rb")) == NULL)
      {
      printf("Can't open the file %s\n", argv[1]);
      exit(1);
      }
    else
      {
        c = argv[2][0];
        while(!feof(f))
          {
            if(isspace(fgetc(f)))
              count++;
          }
        
        char content[count][10];
        rewind(f);
        for(int i = 0; i < count; ++i)
          fscanf(f, "%s ", content[i]);
        
        //printf("Number of word is %d\n",count);
        for(int i = 0; i < count; ++i)
          {
          for(int j = 0; j < max; ++j)
            {
              p = strstr(content[i], list[j]);
              if(p != NULL)
                break;
              
                }
          if(p != NULL)
            for(int k = 0; k < strlen(content[i]); ++k)
              content[i][k] = c;
          p = NULL;
          }
        
        fclose(f);
        f = fopen(argv[1], "wb");
        for(int i = 0; i < count; ++i){
          fprintf(f, "%s", content[i]);
          fprintf(f, "%c",i < count - 1?' ':'\0');
        }
        fprintf(f,"\n");
        fclose(f);
      }
}
