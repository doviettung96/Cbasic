#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
  char name[30];
  char tel[11];
  char email[25];
} phone_addr;

void main(int argc, char** argv) {
  FILE *fptr;
  FILE *f1, *f2;
  int numSplit;
  phone_addr *contact;
  int result;

  if (argc != 5)
  {
    printf("Wrong syntax!\n");
    exit(1);
  }

  if ((fptr = fopen(argv[1], "rb")) == NULL)
  {
    printf("Can't open file %s\n", argv[1]);
    exit(1);
  }
  f1 = fopen(argv[3], "wb");
  f2 = fopen(argv[4], "wb");

  numSplit = atoi(argv[2]);
  contact = (phone_addr*)malloc(numSplit * sizeof(phone_addr));
  result = fread(contact, sizeof(phone_addr), numSplit, fptr);
  fwrite(contact, sizeof(phone_addr), result, f1);
  free(contact);

  contact = (phone_addr*)malloc((MAX - numSplit) * sizeof(phone_addr));
  if (fseek(fptr, numSplit * sizeof(phone_addr), SEEK_SET) != 0)
    printf("Fseek failed\n");
  else
    result = fread(contact, sizeof(phone_addr), MAX - numSplit, fptr);
  fwrite(contact, sizeof(phone_addr), result, f2);

  fclose(fptr);
  fclose(f1);
  fclose(f2);
  free(contact);

}
