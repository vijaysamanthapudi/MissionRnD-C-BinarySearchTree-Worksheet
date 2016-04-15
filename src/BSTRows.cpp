/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
int height(struct node *root);
void LevelNode(struct node* root, int level, int a[],int *len);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

//int* BSTRighttoLeftRows(struct node* root)
//{
//	return NULL;
//}

int *BSTRighttoLeftRows(struct node* root)
{
	int h = height(root);
	int i;
	int *a = (int *)malloc(sizeof(int) * 15);
	int len = 0;
	for (i = 1; i <= h; i++)
	{
		LevelNode(root, i, a,&len);
	}

	return a;

}

int height(struct node *root)
{

	if (root == NULL)
	{
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	if (lh > rh)
	{
		return lh + 1;
	}
	else {
		return rh + 1;
	}
}



void LevelNode(struct node* root, int level, int a[],int *len)
{
	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		a[*len] = root->data;
		(*len)++;
		return;
	}
	else if (level > 1)
	{
		LevelNode(root->right, level - 1, a,len);
		LevelNode(root->left, level - 1, a,len);
	}
}