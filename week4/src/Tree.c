#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void menu() {
	printf("0.�˳�����\n");
	printf("1.��ʼ������������\n");
	printf("2.������\n");
	printf("3.ɾ�����\n");
	printf("4.ǰ������ݹ��\n");
	printf("5.��������ݹ��\n");
	printf("6.��������ݹ��\n");
	printf("7.ǰ������ǵݹ��\n");
	printf("8.��������ǵݹ��\n");
	printf("9.��������ǵݹ��\n");
	printf("10.��α���\n");
	printf("11.���ҽ��\n");
	printf("��ѡ���ܣ�\n");
}

Tree* init()
{
	Tree* t = (Tree*)malloc(sizeof(Tree));
	t->root = NULL;
	if (t != NULL){
		return t;
	}
	else{
		printf("Error\n");
	}

}





