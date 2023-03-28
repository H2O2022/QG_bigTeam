#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "count.h"

void menu() {
	printf("0.退出程序\n");
	printf("1.初始化队列\n");
	printf("2.入队\n");
	printf("3.出队\n");
	printf("4.判断队列是否为空\n");
	printf("5.获取top节点\n");
	printf("6.清空队列\n");
	printf("7.获取队列长度\n");
	printf("8.销毁队列\n");
	printf("9.遍历队列\n");
}

Node* initQueue() {//初始化
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = count;
	q->next = NULL;
	q->hail = NULL;
	return q;
}

void enQueue(Node* q) {//入队
	Node* new = (Node*)malloc(sizeof(Node));
	char* v = (char*)malloc(sizeof(data));
	//v = (void*)val;
	printf("请输入队列的数据(14个字符以内)：");
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

Node* delQueue(Node* q) {//出队
	Node* temp = q;
	Node* queue = q->next;
	queue->hail = temp->hail;
	free(queue->data);
	count--;
	queue->data = count;
	free(temp);
	return queue;
}

void LengthLQueue(Node* q) {//获取长度
	printf("Length:%d\n", (void*)(q->data));
}

void GetHeadLQueue(Node* q) {//获取头节点
	if (q->next != NULL) {
	printf("Top:%s\n", (void*)(q->next->data));
	}
	else {
		printf("队列为空\n");
	}
}

void IsEmptyLQueue(Node* q) {//判断是否为空
	if (q->data == 0) {
		printf("队列为空\n");
	}
	else {
		printf("队列不为空\n");
	}
}

Node* ClearLQueue(Node* q) {//清空队列
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

Node* DestoryLQueue(Node* q) {//销毁队列
	Node* queue = ClearLQueue(q);
	free(queue);
	if (queue == NULL) {
		printf("Success\n");
	}
	queue = NULL;
	return queue;
}

void printQueue(Node* q) {//遍历打印队列
	Node* p = q->next;
	while (p != NULL) {
		printf("%s", (void*)(p->data));
		printf("->");
		p = p->next;
	}
	printf("NULL\n");
}
