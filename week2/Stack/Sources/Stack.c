#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//�˵�����
void menu() {
	printf("command list:\n");
	printf("	0.exit\n");
	printf("	1.initLStack\n");//��ʼ��ջ
	printf("	2.isEmptyLStack\n");//�ж�ջ�Ƿ�Ϊ��
	printf("	3.getTopLStack\n");//�õ�ջ��Ԫ��
	printf("	4.clearLStack\n");//���ջ
	printf("	5.destroyLStack\n");//����ջ
	printf("	6.LStackLength\n");//���ջ����
	printf("	7.pushLStack\n");//��ջ
	printf("	8.popLStack\n");//��ջ
}

//��ʼ��
StackNode* initLStack() {
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	s->data = 0;
	s->next = NULL;
	return s;
}

//�ж�ջ�Ƿ�Ϊ��
void isEmptyLStack(StackNode* s) {
	if (s->data == 0) {
		printf("Stack is empty.\n");
	}
	else {
		printf("Stack is not empty.\n");
	}
}

//�õ�ջ��Ԫ��
void getTopLStack(StackNode* s) {
	printf("The top node is %d\n", s->next->data);
}

//���ջ
void clearLStack(StackNode* s) {
	StackNode* cur = s->next;
	while (cur != NULL) {
		StackNode* temp = cur;
		cur = cur->next;
		free(temp);
		s->data--;
	}
	if (s->next == cur) {
		printf("Success\n");
	}
}

//����ջ
void destroyLStack(StackNode* s) {
	clearLStack(s);
	free(s);
	if (s == NULL) {
		printf("Success\n");
	}
}

//���ջ����
void LStackLength(StackNode* s) {
	printf("The length of Stack is %d.\n", s->data);
}

//��ջ
void pushLStack(StackNode* s, int val) {
	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	new->data = val;
	new->next = s->next;
	s->next = new;
	s->data++;
}

//��ջ
void popLStack(StackNode* s) {
	StackNode* p = s->next;
	s->next = p->next;
	s->data--;
	p->next = NULL;
	free(p);
}

//����ջ
void printStack(StackNode* s) {
	StackNode* p = s->next;
	while (p != NULL) {
		printf("%d", p->data);
		printf("->");
		p = p->next;
	}
	printf("NULL\n");
}