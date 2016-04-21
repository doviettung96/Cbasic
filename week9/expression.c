#include "bintree.h"
#include "stacklib.h"

#define MAX 20
void display(tree_type tree);
int isOperator(char token);
int openLiteral(char token);
int closeLiteral(char token);
int matchLiteral(char x, char y);

void main(int argc, char **argv)
{
	FILE *f;
	int i, j = 0;
	TNode *p;
	stack_type *stack;

	char postfix[MAX];
	char infix[MAX];
	tree_type tree = NULL;
	makeNullTree(&tree);
	stack = iniStack(stack);

	printf("Type in an infix expression\n");
	scanf("%s", infix);
	for (i = 0; i < strlen(infix); ++i)
	{
		if (openLiteral(infix[i]))
			push(infix[i], stack);
		if (closeLiteral(infix[i]))
		{
			while(!openLiteral(postfix[j])) {
				postfix[j] = pop(stack);
				++j;
			}
		}
		if(isOperator(infix[i]))

	}


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
	freeTree(tree);
}

void display(tree_type tree) {
	printf("%s ", (char *)(tree->info));
}

int isOperator(char token) {
	if (token == '+' || token == '-') 
		return 1;
	if(token == '*' || token == '/')
		return 2;
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

//check if the literal is in pair
int matchLiteral(char x, char y)
{
	if (x == '(' && y == ')') return 1;
	if (x == '{' && y == '}') return 1;
	if (x == '[' && y == ']') return 1;
	return 0;
}