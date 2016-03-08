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
	phone_addr *contact;
	int result;
	if (argc != 2)
	{
		printf("Wrong syntax!\n");
		exit(1);
	}

	if ((fptr = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}

	contact = (phone_addr*)malloc(MAX * sizeof(phone_addr));
	result = fread(contact, sizeof(phone_addr), MAX, fptr);
	for (int i = 0; i < result; ++i)
		printf("%-30s\t%-11s\t%-25s\n", contact[i].name, contact[i].tel, contact[i].email);
}