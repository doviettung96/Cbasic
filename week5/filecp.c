#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this program is to compare the corresponding lines of 2 text file
void main(int argc, char** argv) {
	FILE* f;
	FILE* p;
	int n = atoi(argv[3]);
	int dif[n];
	int count = 0;
	char a[50], b[50];

	if ((f = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(1);
	}
	if ((p = fopen(argv[2], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[2]);
		exit(1);
	}

	for (int i = 0; i < n; ++i)
		dif[i] = 0;

	while (!feof(f) && !feof(p)) {
		fscanf(f, "%[^\n]\n", a);
		fscanf(p, "%[^\n]\n", b);
		//printf("%s\n%s\n",a, b);
		if (strcmp(a, b) != 0)
			dif[count] = 1;
		count++;
	}

	for (int i = 0; i <= count; ++i)
		if (dif[i] == 1)
		{
			//printf("The first line where %s and %s differ: %d", argv[1], argv[2], dif[0]);
			printf("The line where %s and %s differ: %d\n", argv[1], argv[2], i + 1);
		}
fclose(f);
fclose(p);
}
