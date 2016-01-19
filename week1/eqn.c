#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void solve(float a, float b, float c);

void main(int argc, char* argv[])
{
  char check[] = "sde";
  float a,b,c;
  if(argc != 5)
    printf("Wrong number of arguments. The program now will be terminated\n");
  else
    if(strcmp(argv[1], check) != 0)
      printf("Wrong syntax\n");
    else
      {
        a = atof(argv[2]);
        b = atof(argv[3]);
        c = atof(argv[4]);
        printf("Equation: %4.2fx^2 + %4.2fx + %4.2f = 0\n",a,b,c);
        solve(a, b, c);
      }
  
}

void solve(float a, float b, float c)
{
  float delta;
  if(a == 0)
    if(b == 0)
      if(c == 0)
        printf("The equation is always true with any x in R\n");
      else
        printf("The equation has no solution\n");
    else
      printf("The equation has only 1 solution x = %4.2f\n",(0 - c) / b);
  else
    {
      delta = b*b - 4*a*c;
      if(delta < 0)
        printf("The equation has no solution\n");
      else
        if(delta == 0)
          printf("The equation has only 1 solution x = %4.2f\n",0.5 * (0 - b) / a);
        else
          printf("The equation has two seperated solutions x1 = %4.2f, x2 = %4.2f\n", 0.5*(-b + sqrt(delta) / a),0.5*(-b - sqrt(delta) / a) );
    }
}
