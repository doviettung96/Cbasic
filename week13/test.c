#include <stdio.h>
void Tri(int n, char c);
void recurTri(int n, char c);

void main() {
	int n;
	char c;
	printf("Type in a number and a character: ");
	scanf("%d%c", &n, &c);
	// Tri(n, c);
	recurTri(n, c);
}

void Tri(int n, char c)
{
	int i = 0, j = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - i; ++j)
			printf("%c", c);
		printf("\n");
	}

}

void recurTri(int n, char c)
{
	int i = 0;
	if (n == 0)
		return;
	for (i = 0; i < n; ++i)
		printf("%c", c);
	printf("\n");
	recurTri(n - 1, c);
}
