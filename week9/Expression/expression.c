#include "bintree.h"
#include "stacklib.h"

#define MAX 40
void display(tree_type tree);
int isOperator(char token);
int isOperand(char token);
int openLiteral(char token);
int closeLiteral(char token);
int popOperator(char poped, char consider);
tree_type binTree(char postfix[]);

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

	// for (i = 0; i < strlen(postfix); ++i)
	// 	printf("%c ", postfix[i]);
	
	tree = binTree(postfix);
	printf("\nThe tree in preorder is: \n");
	preOrder(tree, display);
	printf("\nThe tree in inorder is: \n");
	inOrder(tree, display);
	printf("\nThe tree in postorder is: \n");
	postOrder(tree, display);
	// printf("\nTotal nodes of tree is: %d\n", countNode(tree));
	// printf("Total leaves of tree is: %d\n", countLeaves(tree));
	// printf("The height of the tree is: %d\n", height(tree));
	// printf("Number of internal nodes: %d\n", countNode(tree) - 1 - countLeaves(tree));
	// printf("Number of right children: %d\n", nb_right(tree));
	// p = makeTNode(n);
	// printf("The depth of the %d-th node is: %d\n", n, depth(tree, p, ));
	printf("\n");
	freeTree(tree);
}

void display(tree_type tree) {
	char *temp;
	temp = (char *)tree->info;
	printf("%c ", *temp);
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
	if (isOperator(poped) < isOperator(consider) || (poped == '^' && consider == '^') 
		|| (poped == '+' &&  consider == '+') || (poped == '*' && consider == '*')	)
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

int isOperand(char token) {
	if (!isOperator(token) && !openLiteral(token) && !closeLiteral(token))
		return 1;
	return 0;
}

//construct a binary tree from postfix input
tree_type binTree(char postfix[])
{
	stack_type *stack;
	tree_type t, t1, t2;
	int i;

	stack = iniStack(stack);
	makeNullTree(&t);
	makeNullTree(&t1);
	makeNullTree(&t2);

	for (i = 0; i < strlen(postfix); ++i)
	{
		if (!isOperator(postfix[i]))
		{
			t = makeTNode(&postfix[i]);
			push(t, stack);
		}
		else 
		{
			t = makeTNode(&postfix[i]);
			t1 = pop(stack);
			t2 = pop(stack);
			t->right = t1;
			t->left = t2;
			push(t, stack);
		}
	}
	t = pop(stack);
	return t;
}