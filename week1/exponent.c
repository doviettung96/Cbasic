#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ex(float a, float deviation);

void main(int argc, char* argv[]){
  float dev;
  char e[] = "E";
  float power;
 
  if(argc < 3 || argc > 4)
    printf("Wrong number of arguments. The program now will be terminated\n");
  else
    {
      power = atof(argv[2]);
      if(argc == 3)
        dev = 0;
      else
        dev = atof(argv[3]);
    }
  if(strcmp(argv[1], e) != 0|| power < 0)
    printf("One of the arguments is wrong\n");
  else
    ex(power,dev);
  //printf("Power %d\n",power);
  // printf("Deviation %f\n",dev);
}
          
void ex(float a, float deviation){
  int i;
  float x,y;
  int n;
  if(deviation != 0)
    n = (int)(1.0 / deviation);
  else
    n = 999999;
  x = y = 1;
  //printf("n = %d\n",n);
  for(i = 1; i <= n; ++i)
    {
    y *= a/i;
    x += y;
  }
  printf("E^%4.2f = %4.2f\n",a,x);
}
