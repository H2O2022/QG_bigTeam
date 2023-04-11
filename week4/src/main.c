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
					printf("二叉树已经初始化了\n");
				}
			}
			else
			{
				if (t == NULL) {
					printf("请先初始化二叉树\n");
				}
				else {
					if (f == 2)
					{
						int count = 0;
					count:
						count = 0;
						printf("你要插入多少数据：");
						int m = scanf("%d", &count);
						if (m == 0 || count <= 0) {
							printf("请输入正整数\n");
							while (getchar() != '\n')
								continue;
							goto count;
						}
						int data = 0;
						for (int i = 0; i < count; i++)
						{
						data:
							data = 0;
							printf("请输入你要插入的值：");
							int m = scanf("%d", &data);
							if (m == 0) {
								printf("请输入数字\n");
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
						printf("层序遍历：");
						levelOrder(t);
						printf("\n请输入你要删除的值：");
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
								printf("没有这个结点\n");
							}
						}
						else {
							printf("请输入数字\n");
							while (getchar() != '\n')
								continue;
							goto key;
						}
					}
					else if (f == 4) {
						printf("前序遍历递归版：");
						prev_order(t->root);
						printf("\n");
					}
					else if (f == 5) {
						printf("中序遍历递归版：");
						in_order(t->root);
						printf("\n");
					}
					else if (f == 6) {
						printf("后序遍历递归版：");
						past_order(t->root);
						printf("\n");
					}
					else if (f == 7) {
						printf("前序遍历递归版：");
						preOrder(t->root);
						printf("\n");
					}
					else if (f == 8) {
						printf("中序遍历非递归版：");
						inOrder(t->root);
						printf("\n");
					}
					else if (f == 9) {
						printf("后序遍历非递归版：");
						pastOrder(t->root);
						printf("\n");
					}
					else if (f == 10) {
						printf("层序遍历：");
						levelOrder(t);
						printf("\n");
					}
					else if (f == 11)
					{
						int value = 0;
					value:
						value = 0;
						printf("请输入你要查找的值：");
						int m = scanf("%d", &value);
						if (m == 0) {
							printf("请输入数字\n");
							while (getchar() != '\n')
								continue;
							goto value;
						}
						search(t, value);
					}
					else {
						printf("请输入正确的数字\n");
					}
				}
			}
		}
		else {
			printf("请输入数字\n");
			while (getchar() != '\n')
				continue;
		}
	}
}

