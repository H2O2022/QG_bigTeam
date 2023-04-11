#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = NULL;
	q->fail = NULL;
	return q;
}

void enQueue(Queue* q, Node* temp)
{
	Qnode* new = (Qnode*)malloc(sizeof(Qnode));
	new->mem = temp;
	new->next = NULL;
	if (q->fail == NULL)
	{
		q->head = new;
		q->fail = new;
	}
	else
	{
		q->fail->next = new;
		q->fail = new;
	}
}

Qnode* delQueue(Queue* q)
{
	Qnode* p = q->head;
	if (q->head == q->fail) {
		q->head = NULL;
		q->fail = NULL;
	}
	else {
		q->head = p->next;
	}
	return p;
}


