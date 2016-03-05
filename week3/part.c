#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the phone book structure
typedef struct {
	char name[30];
	char tel[11];
	char email[25];
} phone_addr;

void main(int argc, char** argv)
{
	FILE* fptr;
	phone_addr *phone;
	int num;
	int k;
	int n;

	// if ((fptr = fopen(argv[1], "wb")) == NULL) {
	// 	printf("Can't open the file %s\n", argv[1]);
	// 	exit(1);
	//}
	// n = atoi(argv[2]);
	// phone = (phone_addr*)malloc(n*sizeof(phone_addr));
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d-th contact\n", i + 1);
	// 	printf("Name: "); scanf("%s", phone[i].name);
	// 	printf("Tel: "); scanf("%s", phone[i].tel);
	// 	printf("Email: "); scanf("%s", phone[i].email);
	// }

	// k = fwrite(phone, sizeof(phone_addr), n, fptr);
	// printf("\nFwrite return code = %d\n", k);

	// fclose(fptr);

	fptr = fopen(argv[1], "r + b");

	printf("\nRead from 2st to 5rd contact\n");
	phone = (phone_addr*)malloc(4 * sizeof(phone_addr));
	if (phone == NULL)
		printf("Memory allocation failed\n");
	else if (fseek(fptr, 1*sizeof(phone_addr), SEEK_SET) != 0)
		printf("Fseek failed!\n");
	else
	{
		num = fread(phone, sizeof(phone_addr), 4, fptr);
		printf("Fread return code = %d\n\n", num);
		for (int i = 0; i < 4; ++i)
		{
			printf("%s-", phone[i].name);
			printf("%s-", phone[i].tel);
			printf("%s\n", phone[i].email);
		}
		//modifying some data
		// strcpy(phone[1].name, "Lan Hoa");
		// strcpy(phone[1].tel, "0924224115");
		// strcpy(phone[1].email, "canyousee@gmail.com");
		fseek(fptr, 4*sizeof(phone_addr), SEEK_SET);
		k = fwrite(phone, sizeof(phone_addr), 4, fptr);
		printf("\nFwrite return code = %d\n", k);

		fclose(fptr);
		free(phone);
	}
}
