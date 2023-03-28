#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main() {
	Node* q = NULL;
	menu();
	while (1) {
		int f = 0;
		printf("请选择功能：");
		scanf("%d", &f);
		if (f == 0) {
			printf("Goodbye\n");
			break;
		}
		else if (f == 1) {
			if (q == NULL) {
				q = initQueue();
			}
			else {
				printf("队列已经初始化\n");
			}
		}
		else {
			if (q != NULL) {
				if (f == 2) {
					//char data[10] = {0};
					//printf("请输入队列的数据：");
					//scanf("%s", &data);
					//printf("%s\n", data);
					enQueue(q);
					printQueue(q);
				}
				else if (f == 3) {
					q = delQueue(q);
					printQueue(q);
				}
				else if (f == 4) {
					IsEmptyLQueue(q);
				}
				else if (f == 5) {
					GetHeadLQueue(q);
				}
				else if (f == 6) {
					q = ClearLQueue(q);
				}
				else if (f == 7) {
					LengthLQueue(q);
					printQueue(q);
				}
				else if (f == 8) {
					q = DestoryLQueue(q);
				}
				else if (f == 9) {
					printQueue(q);
				}
				else {
					printf("请输入正确的数字\n");
				}
			}
			else {
				printf("请先初始化队列\n");
			}
		}
	}
}



