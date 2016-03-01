#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int stt;
  int mssv;
  char hoten[30];
  char sdt[11];
  float diem;
} tt;

void main(int argc, char** argv){
  FILE* p;
  FILE* q;

  tt *hs;
  int n;
  int i = 0;
  char a;
  if(argc != 4)
    {
      printf("Wrong syntax!\n");
      exit(1);
    }

  else
    if((p = fopen(argv[1], "rb")) == NULL)
      {
        printf("Can't open file %s\n", argv[1]);
        exit(1);
      }
    else
       if((q = fopen(argv[2], "wb")) == NULL)
      {
        printf("Can't open file %s\n", argv[2]);
        exit(1);
      }
       else
         {
           n = atoi(argv[3]);
           hs = (tt*)malloc(n * sizeof(tt));
           
           for(int i = 0; i < n; ++i)
             {
               fscanf(p, "%d\t%d\t", &hs[i].stt, &hs[i].mssv); 
               fscanf(p, "%[^\t]\t%[^\t]\t%f",hs[i].hoten, hs[i].sdt, &hs[i].diem);
               
               //printf("%s\n",hs[i].hoten);
               //printf("%s\n",hs[i].sdt);
               //printf("%f\n",hs[i].diem);
             }

           for(int i = 0; i < n; ++i)
             {
               printf("%d\t%d\t%s\t%s\t%f\n", hs[i].stt, hs[i].mssv, hs[i].hoten, hs[i].sdt, hs[i].diem);
               fprintf(q, "%d\t%d\t%s\t%s\t%f\n", hs[i].stt, hs[i].mssv, hs[i].hoten, hs[i].sdt, hs[i].diem);
             }
         }
  
  free(hs);
  fclose(p);
  fclose(q);
}
