#pragma once

// 定义单链表节点
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

//用户菜单界面
void menu();

//初始化链表
ListNode* initList();

//创建链表
void createList(ListNode* head);

//插入节点
void insertList(ListNode* head, int index, int value);

//遍历链表
void printList(ListNode* head);

//删除节点
void deleteList(ListNode* head, int index);

//销毁链表
void destroyList(ListNode** head);

//查找节点
void searchList(ListNode* head, int value);

//反转链表
void reverseList(ListNode* head);

//判断链表是否成环
int isloopList(ListNode* head);

//奇偶位对换
void reverseEvenList(ListNode* head);

//查找中间节点
int findMidList(ListNode* head);
