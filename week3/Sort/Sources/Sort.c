#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Sort.h"

void menu() {
	printf("0.�˳�����\n");
	printf("1.��������\n");
	printf("2.�鲢����\n");
	printf("3.��������\n");
	printf("4.��������\n");
	printf("5.������������\n");
	printf("��ѡ���ܣ�\n");
}

void chooseLen() {
	printf("�ɹ�ѡ�����������\n");
	printf("1.10000\n");
	printf("2.50000\n");
	printf("3.200000\n");
	printf("4.100������100k��\n");
	printf("��ѡ����������");
}

int* creatList(int len) {
	int* arr;
	arr = (int*)malloc(len * sizeof(int));
	if (arr == NULL) {
		printf("�ڴ����ʧ��\n");
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
		printf("�ļ���ʧ��\n");
	}
	for (int i = 0; i < len; i++) {
		fscanf(fp, "%d ", &arr[i]);
	}
	fclose(fp);
	printf("�Ѵ�data.txt�ж�������\n");
	system("pause");
}

void writeList(int arr[], int len) {
	FILE* fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
	}
	for (int i = 0; i < len; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
	printf("������������д��data.txt��\n");
	system("pause");
}