#include <stdio.h>
void encrypt(char* a, int distance);

void main(){
  char* c = "a";
  int dis = 3;
  encrypt(c, dis);
  printf("%s\n",c);
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
