#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

unsigned int data = 0;
unsigned int Lcount = 0;
unsigned int Rcount = 0;

int main() {
	menu();
	Tree* t = NULL;
	int f;
	while (1)
	{
		f = 0;
		printf("-->");
		int m = scanf("%d", &f);
		if (m == 1)
		{
			if (f == 0) {
				printf("Goodbye\n");
				break;
			}
			else if (f == 1)
			{
				if (t == NULL) {
					t = init();
					printf("Success\n");
				}
				else {
					printf("�������Ѿ���ʼ����\n");
				}
			}
			else
			{
				if (t == NULL) {
					printf("���ȳ�ʼ��������\n");
				}
				else {
					if (f == 2)
					{
						int count = 0;
					count:
						count = 0;
						printf("��Ҫ����������ݣ�");
						int m = scanf("%d", &count);
						if (m == 0 || count <= 0) {
							printf("������������\n");
							while (getchar() != '\n')
								continue;
							goto count;
						}
						int data = 0;
						for (int i = 0; i < count; i++)
						{
						data:
							data = 0;
							printf("��������Ҫ�����ֵ��");
							int m = scanf("%d", &data);
							if (m == 0) {
								printf("����������\n");
								while (getchar() != '\n')
									continue;
								goto data;
							}
							insert(t, data);
						}
						printf("Success\n");
					}
					else if (f == 3)
					{
						printf("���������");
						levelOrder(t);
						printf("\n��������Ҫɾ����ֵ��");
						while (getchar() != '\n')
							continue;
						int key = 0;
						int m;
					key:
						key = 0;
						m = scanf("%d", &key);
						if (m == 1) {
							t->root = deleteNode(t->root, key);
							if (t->root) {
								printf("Success\n");
							}
							else {
								printf("û��������\n");
							}
						}
						else {
							printf("����������\n");
							while (getchar() != '\n')
								continue;
							goto key;
						}
					}
					else if (f == 4) {
						printf("ǰ������ݹ�棺");
						prev_order(t->root);
						printf("\n");
					}
					else if (f == 5) {
						printf("��������ݹ�棺");
						in_order(t->root);
						printf("\n");
					}
					else if (f == 6) {
						printf("��������ݹ�棺");
						past_order(t->root);
						printf("\n");
					}
					else if (f == 7) {
						printf("ǰ������ݹ�棺");
						preOrder(t->root);
						printf("\n");
					}
					else if (f == 8) {
						printf("��������ǵݹ�棺");
						inOrder(t->root);
						printf("\n");
					}
					else if (f == 9) {
						printf("��������ǵݹ�棺");
						pastOrder(t->root);
						printf("\n");
					}
					else if (f == 10) {
						printf("���������");
						levelOrder(t);
						printf("\n");
					}
					else if (f == 11)
					{
						int value = 0;
					value:
						value = 0;
						printf("��������Ҫ���ҵ�ֵ��");
						int m = scanf("%d", &value);
						if (m == 0) {
							printf("����������\n");
							while (getchar() != '\n')
								continue;
							goto value;
						}
						search(t, value);
					}
					else {
						printf("��������ȷ������\n");
					}
				}
			}
		}
		else {
			printf("����������\n");
			while (getchar() != '\n')
				continue;
		}
	}
}

