#pragma once

typedef struct DuLNode {
	int data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

//�û��˵�����
void menu();

//��ʼ������
void init(DuLNode** head);

//��������
void creatList(DuLNode* head);

//��������
void destroyList(DuLNode** head);

//ɾ���ڵ�
void deleteList(DuLNode* head, int index);

//��������
void printList(DuLNode* head);

//�������ڵ�
void insertBnode(DuLNode* head, int index, int val);

//ǰ�����ڵ�
void insertAnode(DuLNode* head, int index, int val);

//��ת����
//void reverse(DuLNode* head);

