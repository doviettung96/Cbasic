#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct{
  float x,y;
} point;

typedef struct{
  point tam;
	float r;
	int count;
	int giao[10];
} cir;

int check(cir tron1, cir tron2);
float rd();

void main()
{
  int  i, j, max = 0;
	cir *p;
	int n;
    printf("How many circles do you want? ");
    scanf("%d",&n);
    p = (cir*)malloc(n* sizeof(cir));
    
	for(i = 0; i < n; ++i){
      
      printf("The %d-th circle\n", i + 1);
		printf("I%d(x;y) = ", i + 1); 
		//p[i].tam.x = rd();
		//p[i].tam.y = rd();
		scanf("%f;%f",&p[i].tam.x, &p[i].tam.y);
		printf("R%d = ",i + 1); 
		//p[i].r = rd();
		scanf("%f",&p[i].r);
		p[i].count = 0;
	}
    
	for(i = 0; i < n; ++i)
      printf("\nThe %d-th circle: I%d(%.2f;%.2f), R%d = %.2f\n", i +1, i + 1, p[i].tam.x, p[i].tam.y, i + 1, p[i].r);
	
	for(i = 0; i < n - 1; ++i)
      for(j = i + 1 ; j < n; ++j)
        if(check(p[i], p[j]) == 1)
			{
              p[i].giao[(p[i].count)] = j + 1;
              p[j].giao[(p[j].count)] = i + 1;
              p[i].count++;
              p[j].count++;
              
			}
    
    // printf("Error here!\n");
    
	for(i = 0; i < n; ++i)
      if(p[i].count >= max)
        max = p[i].count;
    
	for(i = 0; i < n; ++i)
      if(p[i].count == max)
		{
          printf("\nThe %d-th circle intersect with most of other circles\n", i + 1);
          
          for(j = 0; j < n; ++j)
            if(p[i].giao[j] != 0)
              printf("The %d-th circle intersect with %d-th circle\n",i + 1, p[i].giao[j]);
		}
    free(p);
}


int check(cir tron1, cir tron2){
  point d;
  int kc;
  d.x = (tron1.tam.x - tron2.tam.x);
  d.y = (tron1.tam.y - tron2.tam.y);
  kc = d.x*d.x + d.y*d.y;
  if(kc < (tron1.r + tron2.r)*(tron1.r + tron2.r))
    return 1;
  else
    return 0;
}

float rd(){
  int x;
  srand(time(NULL));
  x = rand()%100;
  return x / 10.0;
}

