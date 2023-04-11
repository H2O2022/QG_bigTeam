#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//�ݹ����

//ǰ�����
void prev_order(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d ", node->data);
	prev_order(node->left);
	prev_order(node->right);
}

//�������
void in_order(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	in_order(node->left);
	printf("%d ", node->data);
	in_order(node->right);
}

//�������
void past_order(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	past_order(node->left);
	past_order(node->right);
	printf("%d ", node->data);
}

//�ǵݹ����

//�ǵݹ�ǰ�����
void preOrder(Node* root)
{
	if (root == NULL) 
		return;

	struct Node* stack[100];
	int top = 0;
	stack[top++] = root;

	while (top > 0) {
		struct Node* node = stack[--top];
		printf("%d ", node->data);

		if (node->right != NULL)
			stack[top++] = node->right;

		if (node->left != NULL)
			stack[top++] = node->left;
	}
}

//�ǵݹ��������
void inOrder(Node* root)
{
	if (root == NULL) {
		return;
	}
	Node* stack[100];
	int top = -1;
	while (root != NULL || top >= 0) {
		while (root != NULL) {
			stack[++top] = root;
			root = root->left;
		}
		Node* node = stack[top--];
		printf("%d ", node->data);
		if (node->right != NULL) {
			root = node->right;
		}
	}
}

//�ǵݹ�������
void pastOrder(Node* root)
{
	if (root == NULL) {
		return;
	}
	Node* stack[100];
	int top = -1;
	Node* lastVisited = NULL;  // ��¼�ϴη��ʵĽڵ�
	while (root != NULL || top >= 0) {
		if (root != NULL) {
			stack[++top] = root;
			root = root->left;
		}
		else {
			Node* node = stack[top];
			if (node->right != NULL && node->right != lastVisited) {
				root = node->right;
			}
			else {
				printf("%d ", node->data);
				lastVisited = node;
				top--;
			}
		}
	}
}

//�������
void levelOrder(Tree* t)
{
	Queue* q = initQueue();
	enQueue(q, t->root);
	Qnode* qnode = NULL;
	while (q->head != NULL && q->fail != NULL)
	{
		qnode = delQueue(q);
		Node* node = qnode->mem;
		printf("%d ", node->data);
		free(qnode);
		if (node->left != NULL){
			enQueue(q, node->left);
		}
		if (node->right != NULL) {
			enQueue(q, node->right);
		}
	}
}



