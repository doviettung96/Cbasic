#include "stacklib.h"

int matchLiteral(char x, char y);
int check(char s[], int length, stack_type *st);

void main(int argc, char **argv) {
	FILE *f;
	char *s;
	int i = 0;
	int numData;
	stack_type *st;

	st = iniStack(st);
	if ((f = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}

	fseek(f, sizeof(char) * 0, SEEK_END);
	numData = ftell(f);
	rewind(f);
	printf("Number of data = %d\n", numData);

	s = (char *)malloc(sizeof(char) * numData);
	for (i = 0; i < numData; ++i)
	{
		s[i] = fgetc(f);
	}
	puts(s);
	
	if (check(s, numData, st))
		printf("The string is made from literal in pairs\n");
	else
		printf("The string is not made from literal in pairs\n");
}

//check if the string is totally made from pair
int check(char s[], int length, stack_type *st)
{
	int i;
	char tem; // result of pop
	for (i = 0; i < length; ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			push(s[i], st);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (empty(st))
				return 0;
			else
			{
				tem = pop(st);
				if (!matchLiteral(tem, s[i]))
					return 0;
			}
		}
	}
	if (empty(st))
		return 1;
	return 0;
}

//check if the literal is in pair
int matchLiteral(char x, char y)
{
	if (x == '(' && y == ')') return 1;
	if (x == '{' && y == '}') return 1;
	if (x == '[' && y == ']') return 1;
	return 0;
}

