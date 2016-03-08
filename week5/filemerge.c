#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
	char name[30];
	char tel[11];
	char email[25];
} phone_addr;

void main(int argc, char **argv) {
	FILE *fptr;
	FILE *f1, *f2;
	phone_addr *contact;

	if (argc != 4)
	{
		printf("Wrong syntax!\n");
		exit(1);
	}

	if ((f1 = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}
	if ((f2 = fopen(argv[2], "rb")) == NULL)
	{
		printf("Can't open file %s\n", argv[2]);
		exit(1);
	}

	if ((fptr = fopen(argv[3], "wb")) == NULL)
	{
		printf("Can't open file %s\n", argv[3]);
		exit(1);
	}

	contact = (phone_addr*)malloc(20 * sizeof(phone_addr));
	fread(contact, sizeof(phone_addr), 10, f1);
	fwrite(contact, sizeof(phone_addr), 10, fptr);
	fread(contact, sizeof(phone_addr), 10, f2);
	fwrite(contact, sizeof(phone_addr), 10, fptr);
	free(contact);


	fclose(f1);
	fclose(f2);
	fclose(fptr);
}