#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void* data;
	struct Node* next;
	struct Node* hail;
}Node;

//int count = 0;

void menu();
Node* initQueue();
void enQueue(Node* q);
Node* delQueue(Node* q);
void LengthLQueue(Node* q);
void GetHeadLQueue(Node* q);
void IsEmptyLQueue(Node* q);
Node* ClearLQueue(Node* q);
Node* DestoryLQueue(Node* q);
void printQueue(Node* q);