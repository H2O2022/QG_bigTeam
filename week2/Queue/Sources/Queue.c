#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "count.h"

void menu() {
	printf("0.�˳�����\n");
	printf("1.��ʼ������\n");
	printf("2.���\n");
	printf("3.����\n");
	printf("4.�ж϶����Ƿ�Ϊ��\n");
	printf("5.��ȡtop�ڵ�\n");
	printf("6.��ն���\n");
	printf("7.��ȡ���г���\n");
	printf("8.���ٶ���\n");
	printf("9.��������\n");
}

Node* initQueue() {//��ʼ��
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = count;
	q->next = NULL;
	q->hail = NULL;
	return q;
}

void enQueue(Node* q) {//���
	Node* new = (Node*)malloc(sizeof(Node));
	char* v = (char*)malloc(sizeof(data));
	//v = (void*)val;
	printf("��������е�����(14���ַ�����)��");
	scanf("%s", v);
	new->data = v;
	new->next = NULL;
	new->hail = NULL;
	if (q->data == 0) {
		q->hail = new;
		q->next = new;
		count++;
		q->data = count;
	}
	else {
		q->hail->next = new;
		q->hail = new;
		count++;
		q->data = count;
	}
	//free(v);
}

Node* delQueue(Node* q) {//����
	Node* temp = q;
	Node* queue = q->next;
	queue->hail = temp->hail;
	free(queue->data);
	count--;
	queue->data = count;
	free(temp);
	return queue;
}

void LengthLQueue(Node* q) {//��ȡ����
	printf("Length:%d\n", (void*)(q->data));
}

void GetHeadLQueue(Node* q) {//��ȡͷ�ڵ�
	if (q->next != NULL) {
	printf("Top:%s\n", (void*)(q->next->data));
	}
	else {
		printf("����Ϊ��\n");
	}
}

void IsEmptyLQueue(Node* q) {//�ж��Ƿ�Ϊ��
	if (q->data == 0) {
		printf("����Ϊ��\n");
	}
	else {
		printf("���в�Ϊ��\n");
	}
}

Node* ClearLQueue(Node* q) {//��ն���
	//Node* cur = q->next;
	while (q->next != NULL) {
		q = delQueue(q);
		//cur = q->next;
	}
	if (q->next == NULL) {
		printf("Success\n");
		return q;
	}
}

Node* DestoryLQueue(Node* q) {//���ٶ���
	Node* queue = ClearLQueue(q);
	free(queue);
	if (queue == NULL) {
		printf("Success\n");
	}
	queue = NULL;
	return queue;
}

void printQueue(Node* q) {//������ӡ����
	Node* p = q->next;
	while (p != NULL) {
		printf("%s", (void*)(p->data));
		printf("->");
		p = p->next;
	}
	printf("NULL\n");
}
