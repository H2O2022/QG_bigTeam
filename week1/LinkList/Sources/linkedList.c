#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


// 定义单链表节点
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// 初始化单链表
ListNode* initList() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->data;
    head->next = NULL;
    return head;
}

// 创建单链表
void createList(ListNode* head) {
    ListNode* p = head;
    int val, count;
    printf("请输入链表的长度：");
    scanf("%d", &count);
    if (count > 0) {
        printf("请输入节点的值：\n");
        for (; count > 0; count--) {
            scanf("%d", &val);
            ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->data = val;
            newNode->next = NULL;
            p->next = newNode;
            p = p->next;
        }
    }
    else {
        printf("输入数据错误\n");
        createList(head);
    }
}

//插入节点
void insertList(ListNode* head, int index, int value) {
    ListNode* p = head;
    int i = 0;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("插入位置超出范围，插入失败！\n");
    }
    else {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = value;
        newNode->next = p->next;
        p->next = newNode;
        printf("插入节点成功\n");
    }
}

//遍历打印链表
void printList(ListNode* head) {
    ListNode* p = head->next;
    //if (p != NULL) {
    //    printf("1");
    //}
    int count = 1;
    while (p != NULL) {
        printf("第%d个节点：", count);
        printf("%d\n", p->data);
        p = p->next;
        count++;
    }
}

//删除节点
void deleteList(ListNode* head, int index) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    if (index == 1) { // 要删除的节点是头节点
        head = head->next;
    }
    else {
        int i = 0;
        while (cur != NULL && i < index) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        if (cur == NULL) {
            printf("没有要删除的节点");
            return;
        }
        prev->next = cur->next;
    }
    free(cur);
}

//销毁链表
void destroyList(ListNode** head) {
    ListNode* cur = *head;
    while (cur != NULL) {
        ListNode* temp = cur;
        cur = cur->next;
        free(temp);
    }
    *head = cur;
    //return head;
}

//查找节点
void searchList(ListNode* head, int value) {
    ListNode* cur = head;
    int i = 0;
    while (cur != NULL && cur->data != value) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) {
        printf("链表中没有该节点\n");
    }
    else {
        printf("该值在第%d个节点\n", i);
    }
}

//反转链表
void reverseList(ListNode* head) {
    ListNode* beg = head->next;
    ListNode* end = beg->next;
    while (end != NULL) {
        beg->next = end->next;
        end->next = head->next;
        head->next = end;
        end = beg->next;
    }
}

//判断链表是否成环
int isloopList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    do {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);
    return 1;
}

//奇偶位对换
void reverseEvenList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = head->next;
    ListNode* cur = prev->next;
    while (1) {
        prev->next = cur->next;
        cur->next = prev;
        temp->next = cur;
        if (prev->next != NULL && prev->next->next != NULL) {
            temp = cur->next;
            prev = prev->next;
            cur = prev->next;
        }
        else {
            break;
        }
    }
}

//查找链表的中间节点
int findMidList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int i = 0;
    while (1) {
        if (fast == NULL || fast->next == NULL) {
            return i;
        }
        slow = slow->next;
        fast = fast->next->next;
        i++;
    }
}

//使链表成环
//void makeLoopList(ListNode* head, int index) {
//    ListNode* cur = head;
//    ListNode* temp = NULL;
//    int i = 0;
//    while(cur->next != NULL){
//        if (i == index) {
//            temp = cur;
//        }
//        cur = cur->next;
//        i++;
//    }
//    if (i >= index) {
//        cur->next = temp;
//    }
//    else {
//        printf("成环位置超出范围，成环失败！\n");
//    }
//}

//用户菜单界面
void menu() {
    printf("************************\n");
    printf("*   0.退出程序         *\n");
    printf("*   1.初始化链表       *\n");
    printf("*   2.添加节点         *\n");
    printf("*   3.插入节点         *\n");
    printf("*   4.删除节点         *\n");
    printf("*   5.遍历链表         *\n");
    printf("*   6.销毁链表         *\n");
    printf("*   7.查找结点         *\n");
    printf("*   8.反转链表         *\n");
    printf("*   9.判断是否成环     *\n");
    printf("*   10.奇偶位对换      *\n");
    printf("*   11.查找中间节点    *\n");
    //printf("*   12.使链表成环      *\n");
    printf("************************\n");
    printf("请选择功能：");
}
