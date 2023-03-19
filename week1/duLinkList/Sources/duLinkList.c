#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//��������ڵ�
typedef struct DuLNode {
	int data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

//�û��˵�����
void menu() {
	printf("***********************\n");
	printf("*   0.�˳�����        *\n");
	printf("*   1.��ʼ������      *\n");
	printf("*   2.��������        *\n");
	printf("*   3.��������        *\n");
	printf("*   4.��ת����        *\n");
	printf("*   5.��������        *\n");
	printf("*   6.ɾ���ڵ�        *\n");
	printf("*   7.ǰ�����ڵ�    *\n");
	printf("*   8.�������ڵ�    *\n");
	printf("***********************\n");
	printf("��ѡ���ܣ�");
}

//��ʼ������
void init(DuLNode** head) {
	*head = (struct DuLNode*)malloc(sizeof(DuLNode));
	DuLNode* tail = (struct DuLNode*)malloc(sizeof(DuLNode));
	(*head)->prior = NULL;
	(*head)->next = tail;
	tail->prior = (*head);
	tail->next = NULL;
}
//DuLNode* init() {
//	DuLNode* head = (struct DuLNode*)malloc(sizeof(DuLNode));
//	DuLNode* tail = (struct DuLNode*)malloc(sizeof(DuLNode));
//	head->prior = NULL;
//	head->next = tail;
//	tail->prior = head;
//	tail->next = NULL;
//	return head;
//}

//��������
void creatList(DuLNode* head) {
	DuLNode* p = head;
	DuLNode* q = head->next;
	int num, val;
	printf("����������ĳ��ȣ�");
	scanf("%d", &num);
	if (num > 0) {
		printf("������ڵ��ֵ��\n");
		for (; num > 0; num--) {
			scanf("%d", &val);
			DuLNode* newNode = (struct DuLNode*)malloc(sizeof(DuLNode));
			newNode->data = val;
			newNode->next = q;
			p->next = newNode;
			q->prior = newNode;
			newNode->prior = p;
			p = p->next;
		}
	}
	else {
		printf("�������ݴ���\n");
		creatList(head);
	}
}

//��������
void destroyList(DuLNode** head) {
	DuLNode* cur = *head;
	while (cur != NULL) {
		DuLNode* temp = cur;
		cur = cur->next;
		free(temp);
	}
	*head = cur;
}

//ɾ���ڵ�
void deleteList(DuLNode* head, int index) {
	DuLNode* cur = head;
	DuLNode* prev = NULL;
	int i = 0;
	while (cur->next != NULL && i < index) {
		prev = cur;
		cur = cur->next;
		i++;
	}
	if (cur->next == NULL) {
		printf("û��Ҫɾ���Ľڵ�\n");
		return;
	}
	prev->next = cur->next;
	cur->next->prior = prev;
	free(cur);
}

//��������
void printList(DuLNode* head) {
	DuLNode* p = head->next;
	int count = 1;
	while (p->next != NULL && count <5) {
		printf("��%d���ڵ��ǣ�", count);
		printf("%d\n", p->data);
		p = p->next;
		count++;
	}
}

//�������ڵ�
void insertBnode(DuLNode* head, int index ,int val) {
	DuLNode* p = head;
	int i = 0;
	while (p->next != NULL && i < index) {
		p = p->next;
		i++;
	}
	if (p->next == NULL) {
		printf("����λ�ó�����Χ������ʧ�ܣ�\n");
	}
	else {
		DuLNode* newNode = (struct Node*)malloc(sizeof(DuLNode));
		newNode->data = val;
		newNode->next = p->next;
		newNode->prior = p;
		p->next = newNode;
		newNode->next->prior = newNode;
		printf("����ڵ�ɹ�\n");
	}
	//DuLNode* newNode = (struct Node*)malloc(sizeof(DuLNode));
	//newNode->data = val;
	//newNode->prior = prevNode;
	//newNode->next = prevNode->next;
	//prevNode->next->prev = newNode;
	//prevNode->next = newNode;
}

//ǰ�����ڵ�
void insertAnode(DuLNode* head, int index, int val) {
	insertBnode(head, index - 1, val);
}

//��ת����
//void reverse(DuLNode* head) {
//	DuLNode* current = head->next;
//	//DuLNode* temp = current->next;
//	DuLNode* temp = NULL;
//	while (current != NULL) {
//		temp = current->prior;
//		current->prior = current->next;
//		current->next = temp;
//		current = current->prior;
//		//current->next = temp->next;
//		//temp->next = head->next;
//		//current->prior->next = temp;
//
//		//current->next->prior = current;
//		//temp->prior = current->prior;
//		//current->prior = temp;
//
//		//current = current->next;
//	}
//	//head->next->prior = NULL;
//	//head->next = temp->prior;
//	if (temp != NULL) {
//		head = temp->prior;
//	}
//}

//void reverse(DuLNode* head) {
//	DuLNode* current = head->next;
//	DuLNode* temp = NULL;
//	while (current != NULL && current->prior != NULL) {
//		temp = current->prior;
//		current->prior = current->next;
//		current->next = temp;
//		current = current->prior;
//	}
//	if (temp != NULL) {
//		head->next = temp->prior;
//		head->next->prior = head;
//	}
//}