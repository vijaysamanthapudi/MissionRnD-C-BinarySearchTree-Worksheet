/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
void post(struct node *root, int *arr, int *i);
void pre(struct node *root, int *arr, int *i);
void in(struct node *root, int *arr, int *i);
struct node{
	struct node * left;
	int data;
	struct node *right;
};


//void inorder(struct node *root, int *arr){
//	
//}
//void preorder(struct node *root, int *arr){
//	
//}
//void postorder(struct node *root, int *arr){
//	
//}
void inorder(struct node *root, int *arr)
{
	if (root == NULL|| arr==NULL)
	{
		return;
	}
	int i = 0;
	in(root, arr, &i);
	
}
void in(struct node *root, int *arr, int *i)
{
	if (root == NULL)
	{
		return;
	}
	in(root->left, arr,i);
	arr[*i] = root->data;
	(*i)++;
	in(root->right, arr,i);

}
void preorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int i = 0;

	pre(root, arr, &i);

}
void pre(struct node *root, int *arr, int *i)
{
	if (root == NULL)
	{
		return;
	}
	*(arr + *i) = root->data;
	(*i)++;
	pre(root->left, arr,i);
	pre(root->right, arr,i);

}
void postorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int i = 0;
	post(root, arr, &i);
}
 
void post(struct node *root, int *arr, int *i)
{
	if (root == NULL)
	{
		return;
	}
	post(root->left, arr,i);
	post(root->right, arr,i);
	*(arr + *i) = root->data;
	(*i)++;
}

