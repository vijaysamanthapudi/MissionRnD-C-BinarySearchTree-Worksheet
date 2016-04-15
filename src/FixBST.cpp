/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
void correctBSTUtil(struct node* root, struct node** first,
struct node** middle, struct node** last,
struct node** prev);
void swap(int* a, int* b);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix_bst(struct node *root)
{
	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;


	correctBSTUtil(root, &first, &middle, &last, &prev);


	if (first && last)
		swap(&(first->data), &(last->data));
	else if (first && middle)
		swap(&(first->data), &(middle->data));

}
void correctBSTUtil(struct node* root, struct node** first,
struct node** middle, struct node** last,
struct node** prev)
{
	if (root)
	{

		correctBSTUtil(root->left, first, middle, last, prev);


		if (*prev && root->data < (*prev)->data)
		{

			if (!*first)
			{
				*first = *prev;
				*middle = root;
			}


			else
				*last = root;
		}

		*prev = root;

		correctBSTUtil(root->right, first, middle, last, prev);
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
