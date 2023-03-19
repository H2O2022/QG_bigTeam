#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//定义链表节点
typedef struct DuLNode {
	int data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

//用户菜单界面
void menu() {
	printf("***********************\n");
	printf("*   0.退出程序        *\n");
	printf("*   1.初始化链表      *\n");
	printf("*   2.创建链表        *\n");
	printf("*   3.销毁链表        *\n");
	printf("*   4.反转链表        *\n");
	printf("*   5.遍历链表        *\n");
	printf("*   6.删除节点        *\n");
	printf("*   7.前面插入节点    *\n");
	printf("*   8.后面插入节点    *\n");
	printf("***********************\n");
	printf("请选择功能：");
}

//初始化链表
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

//创建链表
void creatList(DuLNode* head) {
	DuLNode* p = head;
	DuLNode* q = head->next;
	int num, val;
	printf("请输入链表的长度：");
	scanf("%d", &num);
	if (num > 0) {
		printf("请输入节点的值：\n");
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
		printf("输入数据错误\n");
		creatList(head);
	}
}

//销毁链表
void destroyList(DuLNode** head) {
	DuLNode* cur = *head;
	while (cur != NULL) {
		DuLNode* temp = cur;
		cur = cur->next;
		free(temp);
	}
	*head = cur;
}

//删除节点
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
		printf("没有要删除的节点\n");
		return;
	}
	prev->next = cur->next;
	cur->next->prior = prev;
	free(cur);
}

//遍历链表
void printList(DuLNode* head) {
	DuLNode* p = head->next;
	int count = 1;
	while (p->next != NULL && count <5) {
		printf("第%d个节点是：", count);
		printf("%d\n", p->data);
		p = p->next;
		count++;
	}
}

//后面插入节点
void insertBnode(DuLNode* head, int index ,int val) {
	DuLNode* p = head;
	int i = 0;
	while (p->next != NULL && i < index) {
		p = p->next;
		i++;
	}
	if (p->next == NULL) {
		printf("插入位置超出范围，插入失败！\n");
	}
	else {
		DuLNode* newNode = (struct Node*)malloc(sizeof(DuLNode));
		newNode->data = val;
		newNode->next = p->next;
		newNode->prior = p;
		p->next = newNode;
		newNode->next->prior = newNode;
		printf("插入节点成功\n");
	}
	//DuLNode* newNode = (struct Node*)malloc(sizeof(DuLNode));
	//newNode->data = val;
	//newNode->prior = prevNode;
	//newNode->next = prevNode->next;
	//prevNode->next->prev = newNode;
	//prevNode->next = newNode;
}

//前面插入节点
void insertAnode(DuLNode* head, int index, int val) {
	insertBnode(head, index - 1, val);
}

//反转链表
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