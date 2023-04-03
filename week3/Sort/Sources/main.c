#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Sort.h"

int main() {
	while (1) {
		menu();
		int f = 0;
		int length = 0;
		int c = 0;
		int* arr;
		printf("-->");
		scanf("%d", &f);
		if (f == 0) {
			printf("Goodbye\n");
			break;
		}
		//选择数据量
		chooseLen();
		int t = scanf("%d", &c);
		if (t == 1) {
			if (c == 1)
				length = 10000;
			else if (c == 2)
				length = 50000;
			else if (c == 3)
				length = 200000;
			else if (c == 4)
				length = 100;
			else {
				printf("请输入正确的数字\n");
				continue;
			}
			arr = creatList(length);
			FILE* fp = fopen("data.txt", "w");
			if (fp == NULL) {
				printf("文件打开失败\n");
			}
			for (int i = 0; i < length; i++) {
				fprintf(fp, "%d ", arr[i]);
			}
			fclose(fp);
			printf("未排序数据已写入data.txt中\n");
			system("pause");
		}
		else {
			printf("请输入数字\n");
			continue;
		}
		//排序
		if (f == 1) {
			if (c != 4) {
				clock_t start = clock();
				insertSort(arr, length);
				clock_t diff = clock() - start;
				printList(arr, length);
				printf("插入排序%d个数据需要 %d ms\n",length ,diff);
				writeList(arr, length);
				free(arr);
			}
			else {
				clock_t start = clock();
				for (int i = 1; i < 100000; i++) {
					insertSort(arr, length);
					free(arr);
					arr = creatList(length);
				}
				insertSort(arr, length);
				clock_t diff = clock() - start;
				writeList(arr, length);
				printf("插入排序%d个数据100k次需要 %d ms\n", length, diff);
			}
		}
		else if (f == 2) {
			if (c != 4) {
				clock_t start = clock();
				MergeSort(arr, length);
				clock_t diff = clock() - start;
				printList(arr, length);
				printf("归并排序%d个数据需要 %d ms\n",length, diff);
				writeList(arr, length);
				free(arr);
			}
			else {
				clock_t start = clock();
				for (int i = 1; i < 100000; i++) {
					MergeSort(arr, length);
					free(arr);
					arr = creatList(length);
				}
				MergeSort(arr, length);
				clock_t diff = clock() - start;
				writeList(arr, length);
				printf("归并排序%d个数据100k次需要 %d ms\n", length, diff);
			}
		}
		else if (f == 3) {
			if (c != 4) {
				clock_t start = clock();
				quickSort(arr, length);
				clock_t diff = clock() - start;
				printList(arr, length);
				printf("快速排序%d个数据需要 %d ms\n",length, diff);
				writeList(arr, length);
				free(arr);
			}
			else {
				clock_t start = clock();
				for (int i = 1; i < 100000; i++) {
					quickSort(arr, length);
					free(arr);
					arr = creatList(length);
				}
				quickSort(arr, length);
				clock_t diff = clock() - start;
				writeList(arr, length);
				printf("快速排序%d个数据100k次需要 %d ms\n", length, diff);
			}
		}
		else if (f == 4){
			if (c != 4) {
				clock_t start = clock();
				countSort(arr, length);
				clock_t diff = clock() - start;
				printList(arr, length);
				printf("计数排序%d个数据需要 %d ms\n",length, diff);
				writeList(arr, length);
				free(arr);
			}
			else {
				clock_t start = clock();
				for (int i = 1; i < 100000; i++) {
					countSort(arr, length);
					free(arr);
					arr = creatList(length);
				}
				countSort(arr, length);
				clock_t diff = clock() - start;
				writeList(arr, length);
				printf("计数排序%d个数据100k次需要 %d ms\n", length, diff);
			}
		}
		else if (f == 5) {
			if (c != 4) {
				clock_t start = clock();
				radixCountSort(arr, length);
				clock_t diff = clock() - start;
				printList(arr, length);
				printf("基数计数排序%d个数据需要 %d ms\n",length, diff);
				writeList(arr, length);
				free(arr);
			}
			else {
				clock_t start = clock();
				for (int i = 1; i < 100000; i++) {
					radixCountSort(arr, length);
					free(arr);
					arr = creatList(length);
				}
				radixCountSort(arr, length);
				clock_t diff = clock() - start;
				writeList(arr, length);
				printf("基数计数排序%d个数据100k次需要 %d ms\n", length, diff);
			}
		}
		else {
			printf("请输入正确的数字\n");
		}
	}
	return 0;
}


