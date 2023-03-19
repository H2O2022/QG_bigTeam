#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "duLinkList.h"

int main() {
	DuLNode* head = NULL;
	//DuLNode* tail = NULL;
	while (1) {
		int f;
		menu();
		scanf("%d", &f);
		if (f == 0) {
			printf("goodbye\n");
			break;
		}
		else if (f == 1) {
			init(&head);
			DuLNode* tail = head->next;
			printf("链表初始化完成\n");
		}
		else if (f == 2) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next != NULL){
				printf("已经创建好链表了，再次创建请先销毁链表\n");
			}
			else {
				creatList(head);
			}
		}
		else if (f == 3) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				destroyList(head);
			}
		}
		else if (f == 4) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				printf("反转太难了，实在写不出来了！！！！！");
				//reverse(head);
				//printf("链表反转成功\n");
			}
		}
		else if (f == 5) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				printList(head);
			}
		}
		else if (f == 6) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				printList(head);
				printf("请选择你要删除第几个节点：");
				int index;
				scanf("%d", &index);
				if (index > 0) {
				deleteList(head, index);
				printf("删除节点成功\n");
				}
				else {
					printf("没有要删除的节点\n");
				}
			}
		}
		else if (f == 7) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				printList(head);
				int index, value;
				printf("请选择你要在第几个节点前插入数据：\n");
				scanf("%d", &index);
				printf("请输入你要插入的节点值：\n");
				scanf("%d", &value);
				insertAnode(head, index, value);
			}
		}
		else if (f == 8) {
			if (head == NULL) {
				printf("请先初始化链表\n");
			}
			else if (head->next->next == NULL) {
				printf("链表为空，请先添加节点\n");
			}
			else {
				printList(head);
				int index, value;
				printf("请选择你要在第几个节点后插入数据：\n");
				scanf("%d", &index);
				printf("请输入你要插入的节点值：\n");
				scanf("%d", &value);
				insertBnode(head, index, value);
			}
		}
		else {
			printf("输入不规范\n");
		}
	}
}
