#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// main函数
int main() {
    ListNode* head = NULL;
    while (1) {
        int f1;
        menu();
        scanf("%d", &f1);
        if (f1 == 0) {//结束程序
            printf("goodbye\n");
            break;
        }
        else if (f1 == 1) {//初始化链表
            head = initList();
            printf("链表初始化完成\n");
        }
        else if (f1 == 2) {//创建链表
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else {
                createList(head);
            }
        }
        else if (f1 == 3) {//插入节点
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                printList(head);
                int index, value;
                printf("请选择你要在第几个节点后插入数据：\n");
                scanf("%d", &index);
                printf("请输入你要插入的节点值：\n");
                scanf("%d", &value);
                insertList(head, index, value);
            }
        }
        else if (f1 == 4) {//删除节点
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                printList(head);
                printf("请选择你要删除第几个节点：");
                int index;
                scanf("%d", &index);
                deleteList(head, index);
                printf("删除节点成功\n");
            }
        }
        else if (f1 == 5) {//遍历链表
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                printList(head);
            }
        }
        else if (f1 == 6) {//销毁链表
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                destroyList(&head);
                printf("销毁成功\n");
            }
        }
        else if (f1 == 7) {//查找节点
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                printf("请输入你要查找的值：");
                int value;
                scanf("%d", &value);
                searchList(head, value);
            }
        }
        else if (f1 == 8) {//反转链表
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                reverseList(head);
                printf("反转链表成功\n");
            }
        }
        else if (f1 == 9) {//判断是否成环
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                int ans = isloopList(head);
                if (ans == 1) {
                    printf("链表成环\n");
                }
                else {
                    printf("链表不成环\n");
                }
            }
        }
        else if (f1 == 10) {//奇偶位对换
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                reverseEvenList(head);
                printf("奇偶对换成功\n");
            }
        }
        else if (f1 == 11) {//查找中间节点
            if (head == NULL) {
                printf("请先初始化链表\n");
            }
            else if (head->next == NULL) {
                printf("链表为空，请先添加节点\n");
            }
            else {
                int ans;
                ans = findMidList(head);
                printf("中间节点是第%d个\n", ans);
            }
        }
        //else if (f1 == 12) {
        //    int index;
        //    printList(head);
        //    printf("请输入你想链表末端指向第几个节点：");
        //    scanf("%d", &index);
        //    makeLoopList(head, index);
        //}
        else {
            printf("输入不规范\n");
        }
    }
    return 0;
}
