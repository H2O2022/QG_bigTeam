#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//菜单界面
void menu() {
	printf("command list:\n");
	printf("	0.exit\n");
	printf("	1.initLStack\n");//初始化栈
	printf("	2.isEmptyLStack\n");//判断栈是否为空
	printf("	3.getTopLStack\n");//得到栈顶元素
	printf("	4.clearLStack\n");//清空栈
	printf("	5.destroyLStack\n");//销毁栈
	printf("	6.LStackLength\n");//检测栈长度
	printf("	7.pushLStack\n");//入栈
	printf("	8.popLStack\n");//出栈
}

//初始化
StackNode* initLStack() {
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	s->data = 0;
	s->next = NULL;
	return s;
}

//判断栈是否为空
void isEmptyLStack(StackNode* s) {
	if (s->data == 0) {
		printf("Stack is empty.\n");
	}
	else {
		printf("Stack is not empty.\n");
	}
}

//得到栈顶元素
void getTopLStack(StackNode* s) {
	printf("The top node is %d\n", s->next->data);
}

//清空栈
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

//销毁栈
void destroyLStack(StackNode* s) {
	clearLStack(s);
	free(s);
	if (s == NULL) {
		printf("Success\n");
	}
}

//检测栈长度
void LStackLength(StackNode* s) {
	printf("The length of Stack is %d.\n", s->data);
}

//入栈
void pushLStack(StackNode* s, int val) {
	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	new->data = val;
	new->next = s->next;
	s->next = new;
	s->data++;
}

//出栈
void popLStack(StackNode* s) {
	StackNode* p = s->next;
	s->next = p->next;
	s->data--;
	p->next = NULL;
	free(p);
}

//遍历栈
void printStack(StackNode* s) {
	StackNode* p = s->next;
	while (p != NULL) {
		printf("%d", p->data);
		printf("->");
		p = p->next;
	}
	printf("NULL\n");
}