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
			printf("û��������\n");
	}
	else if (temp->data > val)
	{
		if (temp->left != NULL)
			searchNode(temp->left, val);
		else
			printf("û��������\n");
	}
	else
		printf("�������ڶ�������\n");
}

void search(Tree* t, int val)
{
	searchNode(t->root, val);
}