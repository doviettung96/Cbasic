#include "bintree.h"
#include "stack.h"

#define MAX 40
void display(tree_type tree);
int isOperator(char token);
int isOperand(char token);
int openLiteral(char token);
int closeLiteral(char token);
int popOperator(char poped, char consider);
void infixtoPostfix(char *result);
tree_type binTree(char postfix[]);



void main()
{
	int i;
	int length;
	tree_type tree = NULL;
	makeNullTree(&tree);
	char postfix[MAX];

	infixtoPostfix(postfix);
	// temp = (char *)malloc(sizeof(char));

	// for (i = 0; i < strlen(postfix); ++i)
	// 	printf("%c ", postfix[i]);

//Create a binary tree from postfix input
	tree = binTree(postfix);

//Use functions with binary tree
	reverseTree(&tree);

	printf("\nThe tree in preorder is: \n");
	preOrder(tree, display);
	printf("\nThe tree in inorder is: \n");
	inOrder(tree, display);
	printf("\nThe tree in postorder is: \n");
	postOrder(tree, display);

	printf("\nTotal nodes of tree is: %d\n", countNode(tree));
	printf("Total leaves of tree is: %d\n", countLeaves(tree));
	printf("The height of the tree is: %d\n", height(tree));
	printf("Number of internal nodes: %d\n", countNode(tree) - countLeaves(tree));
	printf("Number of right children: %d\n", nb_right(tree));
	// p = makeTNode(n);
	// printf("The depth of the %d-th node is: %d\n", n, depth(tree, p, ));
	printf("\n");

	freeTree(tree);

}

void display(tree_type tree) {
	if (tree != NULL)
		printf("%c ", tree->info);
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

void infixtoPostfix(char postfix[MAX]) {
	int i = 0, j = 0;
	char *temp;
	char infix[MAX];
	stack_type *stack = iniStack();

	printf("Type in an infix expression\n");
	scanf("%s", infix);

	//This part is about to convert an infix expression into postfix
	for (i = 0; i < strlen(infix); ++i)
	{
		//if we meet open literal likes (, just push into stack
		if (openLiteral(infix[i]))
			push(&infix[i], stack);

		//if we meet the close literal likes ), keep poping from stack until meet the corresponding open literal
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

		//pop out of the stack the operators until meet the lower-precedence operator, or same precedence but right associatiation
		//after that, push the considered operator into stack
		else if (isOperator(infix[i]))
		{
			while (!Sempty(stack))
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
		//meet operands, just use it
		else if (isOperand(infix[i]))
		{
			postfix[j] = infix[i];
			++j;
		}
	}

	//finally, pop all the remaining operators in the stack, add to the end of the storing array
	while (!Sempty(stack))
	{
		temp = (char *)pop(stack);
		postfix[j] = *temp;
		++j;
	}

	freeStack(stack);
}

//construct a binary tree from postfix input
tree_type binTree(char postfix[])
{
	stack_type *stack = iniStack();
	tree_type t, t1, t2;
	int i;

	makeNullTree(&t);
	// makeNullTree(&t1);
	// makeNullTree(&t2);

	for (i = 0; postfix[i] != '\0'; ++i)
	{
		// printf("%c\n", postfix[i]);
		if (isOperand(postfix[i]))
		{
			t = makeTNode(postfix[i]);
			push(t, stack);
		}
		else if (isOperator(postfix[i]))
		{
			t = makeTNode(postfix[i]);
			t1 = pop(stack);
			t2 = pop(stack);
			t->right = t1;
			t->left = t2;
			push(t, stack);
		}
	}
	t = pop(stack);
	// freeTree(t1);
	// freeTree(t2);
	freeStack(stack);
	return t;
}