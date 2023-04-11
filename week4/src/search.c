#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"



void searchNode(Node* temp, int val)
{
	if (temp->data < val){
		if (temp->right != NULL)
			searchNode(temp->right, val);
		else
			printf("没有这个结点\n");
	}
	else if (temp->data > val)
	{
		if (temp->left != NULL)
			searchNode(temp->left, val);
		else
			printf("没有这个结点\n");
	}
	else
		printf("这个结点在二叉树中\n");
}

void search(Tree* t, int val)
{
	searchNode(t->root, val);
}