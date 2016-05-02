#include "bst.h"
#include "queue.h"

void breadth_first(tree_type tree)
{
	queue_type *q; // queue of pointers

	if (tree != NULL) {
		enQueue(tree, q);
		while (!Qempty(q)) {
			tree = deQueue(q);
			printf("%d ", tree->info);
			if (tree->left != NULL)
				enQueue(tree->left, q);
			if (tree->right != NULL)
				enQueue(tree->right, q);
		}
	}
}