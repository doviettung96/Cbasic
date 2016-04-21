#include "bintree.h"
#include "stacklib.h"

#define MAX 30
void display(tree_type tree);
int isOperator(char token);
int isOperand(char token);
int openLiteral(char token);
int closeLiteral(char token);
int popOperator(char poped, char consider);
int matchLiteral(char x, char y);

void main(int argc, char **argv)
{
	FILE *f;
	int i = 0, j = 0;
	TNode *p;
	stack_type *stack;
	char *temp;
	char postfix[MAX];
	char infix[MAX];
	tree_type tree = NULL;
	makeNullTree(&tree);
	stack = iniStack(stack);

	temp = (char *)malloc(sizeof(char));
	printf("Type in an infix expression\n");
	scanf("%s", infix);


	for (i = 0; i < strlen(infix); ++i)
	{
		if (openLiteral(infix[i]))
			push(&infix[i], stack);

		else if (closeLiteral(infix[i]))
		{
			while (1)
			{
				temp = (char *)pop(stack);
				if (openLiteral(*temp))
					break;
				postfix[j] = *temp;
				++j;
			}
		}

		else if (isOperator(infix[i]))
		{
			while (!empty(stack))
			{
				temp = (char*) stack->top->element;
				if (popOperator(*temp, infix[i]))
					break;
				temp = (char *)pop(stack);
				postfix[j] = *temp;
				++j;
			}
			push(&infix[i], stack);
		}
		else if (isOperand(infix[i]))
		{
			postfix[j] = infix[i];
			++j;
		}
	}

	while (!empty(stack))
	{
		temp = (char *)pop(stack);
		postfix[j] = *temp;
		++j;
	}

	for (i = 0; i < strlen(postfix); ++i)
		printf("%c ", postfix[i]);
	printf("\n");

	// printf("\nThe tree in preorder is: \n");
	// preOrder(tree, display);
	// printf("\nThe tree in inorder is: \n");
	// inOrder(tree, display);
	// printf("\nThe tree in postorder is: \n");
	// postOrder(tree, display);
	// printf("\nTotal nodes of tree is: %d\n", countNode(tree));
	// printf("Total leaves of tree is: %d\n", countLeaves(tree));
	// printf("The height of the tree is: %d\n", height(tree));
	// printf("Number of internal nodes: %d\n", countNode(tree) - 1 - countLeaves(tree));
	// printf("Number of right children: %d\n", nb_right(tree));
	// p = makeTNode(n);
	// printf("The depth of the %d-th node is: %d\n", n, depth(tree, p, ));
	freeTree(tree);
}

void display(tree_type tree) {
	printf("%s ", (char *)(tree->info));
}

int isOperand(char token) {
	if (token <= '9' && token >= '0')
		return 1;
	return 0;
}

int isOperator(char token) {
	if (token == '+' || token == '-')
		return 1;
	if (token == '*' || token == '/' || token == '%')
		return 2;
	if (token == '^')
		return 3;
	return 0;
}

//if the operator meet some requirement, they will be pop
int popOperator(char poped, char consider)
{
	if (isOperator(poped) < isOperator(consider) || (isOperator(poped) == 3 && isOperator(consider) == 3))
		return 1;
	return 0;
}

int openLiteral(char token) {
	if (token == '(' || token == '[' || token == '{')
		return 1;
	return 0;
}

int closeLiteral(char token) {
	if (token == ')' || token == ']' || token == '}')
		return 1;
	return 0;
}

int matchLiteral(char x, char y)
{
	if (x == '(' && y == ')') return 1;
	if (x == '{' && y == '}') return 1;
	if (x == '[' && y == ']') return 1;
	return 0;
}