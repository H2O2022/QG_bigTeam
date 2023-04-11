#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void menu() {
	printf("0.退出程序\n");
	printf("1.初始化二叉排序树\n");
	printf("2.插入结点\n");
	printf("3.删除结点\n");
	printf("4.前序遍历递归版\n");
	printf("5.中序遍历递归版\n");
	printf("6.后序遍历递归版\n");
	printf("7.前序遍历非递归版\n");
	printf("8.中序遍历非递归版\n");
	printf("9.后序遍历非递归版\n");
	printf("10.层次遍历\n");
	printf("11.查找结点\n");
	printf("请选择功能：\n");
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





