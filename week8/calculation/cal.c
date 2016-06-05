#include "stack.h"
#include "ctype.h"

int cal(char token, int op1, int op2);

void main(int argc, char **argv) {
	int i = 0;
	stack_type *s;
	int result;
	int *op1, *op2;
	char token;
	int input;

	s = iniStack();

	for (i = 1; argv[i] != NULL; ++i)
	{
		if (isalnum(argv[i][0]))
		{
			input = atoi(argv[i]);
			push(&input, s);
		}
		else
		{
			op2 = (int*)pop(s);
			op1 = (int*)pop(s);
			printf("%d %d\n", *op1, *op2);
			token = argv[i][0];
			result = cal(token, *op1 , *op2);
			push(&result, s);
		}
	}

	printf("Result = ");
	printf("%d\n", result);
	freeStack(s);
}



//token depends on the notNumber() funtion
int cal(char token, int op1, int op2) {
	int result;
	switch (token) {
	case '+': result = op1 + op2; break;
	case '-': result = op1 - op2; break;
	case '.': result = op1 * op2; break;
	case '/':
		if (op2 == 0)
		{
			printf("Can't devide by 0\n");
			exit(1);
		}
		result = op1 / op2;
		break;
	}
	return result;
}

