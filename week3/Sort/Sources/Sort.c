#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Sort.h"

void menu() {
	printf("0.退出程序\n");
	printf("1.插入排序\n");
	printf("2.归并排序\n");
	printf("3.快速排序\n");
	printf("4.计数排序\n");
	printf("5.基数计数排序\n");
	printf("请选择功能：\n");
}

void chooseLen() {
	printf("可供选择的数据量：\n");
	printf("1.10000\n");
	printf("2.50000\n");
	printf("3.200000\n");
	printf("4.100个数据100k次\n");
	printf("请选择数据量：");
}

int* creatList(int len) {
	int* arr;
	arr = (int*)malloc(len * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
	}
	else {
		for (int i = 0; i < len; i++) {
			arr[i] = rand();
		}
		return arr;
	}
}

void printList(int arr[], int len) {
	//printf("%d\n", arr[0]);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void readList(int arr[], int len) {
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
	}
	for (int i = 0; i < len; i++) {
		fscanf(fp, "%d ", &arr[i]);
	}
	fclose(fp);
	printf("已从data.txt中读入数据\n");
	system("pause");
}

void writeList(int arr[], int len) {
	FILE* fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("文件打开失败\n");
	}
	for (int i = 0; i < len; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
	printf("已排序数据已写入data.txt中\n");
	system("pause");
}