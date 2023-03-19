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
			printf("�����ʼ�����\n");
		}
		else if (f == 2) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next != NULL){
				printf("�Ѿ������������ˣ��ٴδ���������������\n");
			}
			else {
				creatList(head);
			}
		}
		else if (f == 3) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				destroyList(head);
			}
		}
		else if (f == 4) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				printf("��ת̫���ˣ�ʵ��д�������ˣ���������");
				//reverse(head);
				//printf("����ת�ɹ�\n");
			}
		}
		else if (f == 5) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				printList(head);
			}
		}
		else if (f == 6) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				printList(head);
				printf("��ѡ����Ҫɾ���ڼ����ڵ㣺");
				int index;
				scanf("%d", &index);
				if (index > 0) {
				deleteList(head, index);
				printf("ɾ���ڵ�ɹ�\n");
				}
				else {
					printf("û��Ҫɾ���Ľڵ�\n");
				}
			}
		}
		else if (f == 7) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				printList(head);
				int index, value;
				printf("��ѡ����Ҫ�ڵڼ����ڵ�ǰ�������ݣ�\n");
				scanf("%d", &index);
				printf("��������Ҫ����Ľڵ�ֵ��\n");
				scanf("%d", &value);
				insertAnode(head, index, value);
			}
		}
		else if (f == 8) {
			if (head == NULL) {
				printf("���ȳ�ʼ������\n");
			}
			else if (head->next->next == NULL) {
				printf("����Ϊ�գ�������ӽڵ�\n");
			}
			else {
				printList(head);
				int index, value;
				printf("��ѡ����Ҫ�ڵڼ����ڵ��������ݣ�\n");
				scanf("%d", &index);
				printf("��������Ҫ����Ľڵ�ֵ��\n");
				scanf("%d", &value);
				insertBnode(head, index, value);
			}
		}
		else {
			printf("���벻�淶\n");
		}
	}
}
