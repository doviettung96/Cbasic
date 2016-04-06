#include "stacklib.h"


element_type cal(char token, element_type op1, element_type op2);

void main(int argc, char **argv) {
	int i = 0;
	stack_type *s;
	element_type result;
	element_type op1, op2;
	char token;
	element_type input;

	s = iniStack(s);

	for (i = 1; argv[i] != NULL; ++i)
	{
		if (isalnum(argv[i][0]))
		{
			input = atoi(argv[i]);
			push(input, s);
		}
		else
		{
			op2 = pop(s);
			op1 = pop(s);
			printf("%d %d\n", op1, op2);
			token = argv[i][0];
			result = cal(token, op1 , op2);
			push(result, s);
		}
	}

	printf("Result = ");

	printf("%d", pop(s));
	printf("\n");
}



//token depends on the notNumber() funtion
element_type cal(char token, element_type op1, element_type op2) {
	element_type result;
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

