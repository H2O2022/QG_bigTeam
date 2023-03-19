#pragma once

// ���嵥����ڵ�
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

//�û��˵�����
void menu();

//��ʼ������
ListNode* initList();

//��������
void createList(ListNode* head);

//����ڵ�
void insertList(ListNode* head, int index, int value);

//��������
void printList(ListNode* head);

//ɾ���ڵ�
void deleteList(ListNode* head, int index);

//��������
void destroyList(ListNode** head);

//���ҽڵ�
void searchList(ListNode* head, int value);

//��ת����
void reverseList(ListNode* head);

//�ж������Ƿ�ɻ�
int isloopList(ListNode* head);

//��żλ�Ի�
void reverseEvenList(ListNode* head);

//�����м�ڵ�
int findMidList(ListNode* head);
