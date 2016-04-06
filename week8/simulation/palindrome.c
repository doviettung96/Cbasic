#include "queue.h"
#include "stacklib.h"

int check(char c1, char c2);

void main() {
	stack_type *s;
	queue_type *q;
	int i = 0;
	element_type input[20];
	char c1, c2;

	s = iniStack(s);
	q = iniQueue(q);


	printf("Type in a word\n");
	scanf("%s", input);

	for (i = 0; i < strlen(input); ++i) {
		push(input[i], s);
		enQueue(input[i], q);
	}

	while (!Qempty(q))
	{
		c1 = pop(s);
		c2 = deQueue(q);
		// printf("c1 = %c, c2 = %c\n", c1, c2);
		if (!check(c1, c2))
		{
			printf("Not match\n");
			exit(1);
		}
	}

	printf("%s is a palindrome string\n", input);
}

int check(char c1, char c2) {
	if (c1 != c2)
		return 0;
	return 1;
}