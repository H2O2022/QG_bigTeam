#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"


void insertNode(Node* temp, int val)
{
	if (temp->data < val)
	{
		if (temp->right != NULL) {
			insertNode(temp->right, val);
		}
		else {
			Node* new = (Node*)malloc(sizeof(Node));
			new->data = val;
			new->left = NULL;
			new->right = NULL;
			temp->right = new;
		}
	}
	else if (temp->data > val)
	{
		if (temp->left != NULL) {
			insertNode(temp->left, val);
		}
		else {
			Node* new = (Node*)malloc(sizeof(Node));
			new->data = val;
			new->left = NULL;
			new->right = NULL;
			temp->left = new;
		}
	}
	else {
		printf("插入值已经存在\n");
	}
}


void insert(Tree* t, int val)
{
	if (t->root == NULL)
	{
		Node* new = (Node*)malloc(sizeof(Node));
		new->data = val;
		new->left = NULL;
		new->right = NULL;
		t->root = new;
	}
	else
	{
		Node* temp = t->root;
		insertNode(temp, val);
	}
}