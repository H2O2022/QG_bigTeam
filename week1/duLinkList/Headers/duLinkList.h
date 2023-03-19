#pragma once

typedef struct DuLNode {
	int data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

//用户菜单界面
void menu();

//初始化链表
void init(DuLNode** head);

//创建链表
void creatList(DuLNode* head);

//销毁链表
void destroyList(DuLNode** head);

//删除节点
void deleteList(DuLNode* head, int index);

//遍历链表
void printList(DuLNode* head);

//后面插入节点
void insertBnode(DuLNode* head, int index, int val);

//前面插入节点
void insertAnode(DuLNode* head, int index, int val);

//反转链表
//void reverse(DuLNode* head);

