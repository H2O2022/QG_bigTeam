#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


// ���嵥����ڵ�
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// ��ʼ��������
ListNode* initList() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->data;
    head->next = NULL;
    return head;
}

// ����������
void createList(ListNode* head) {
    ListNode* p = head;
    int val, count;
    printf("����������ĳ��ȣ�");
    scanf("%d", &count);
    if (count > 0) {
        printf("������ڵ��ֵ��\n");
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
        printf("�������ݴ���\n");
        createList(head);
    }
}

//����ڵ�
void insertList(ListNode* head, int index, int value) {
    ListNode* p = head;
    int i = 0;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("����λ�ó�����Χ������ʧ�ܣ�\n");
    }
    else {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = value;
        newNode->next = p->next;
        p->next = newNode;
        printf("����ڵ�ɹ�\n");
    }
}

//������ӡ����
void printList(ListNode* head) {
    ListNode* p = head->next;
    //if (p != NULL) {
    //    printf("1");
    //}
    int count = 1;
    while (p != NULL) {
        printf("��%d���ڵ㣺", count);
        printf("%d\n", p->data);
        p = p->next;
        count++;
    }
}

//ɾ���ڵ�
void deleteList(ListNode* head, int index) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    if (index == 1) { // Ҫɾ���Ľڵ���ͷ�ڵ�
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
            printf("û��Ҫɾ���Ľڵ�");
            return;
        }
        prev->next = cur->next;
    }
    free(cur);
}

//��������
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

//���ҽڵ�
void searchList(ListNode* head, int value) {
    ListNode* cur = head;
    int i = 0;
    while (cur != NULL && cur->data != value) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) {
        printf("������û�иýڵ�\n");
    }
    else {
        printf("��ֵ�ڵ�%d���ڵ�\n", i);
    }
}

//��ת����
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

//�ж������Ƿ�ɻ�
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

//��żλ�Ի�
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

//����������м�ڵ�
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

//ʹ����ɻ�
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
//        printf("�ɻ�λ�ó�����Χ���ɻ�ʧ�ܣ�\n");
//    }
//}

//�û��˵�����
void menu() {
    printf("************************\n");
    printf("*   0.�˳�����         *\n");
    printf("*   1.��ʼ������       *\n");
    printf("*   2.��ӽڵ�         *\n");
    printf("*   3.����ڵ�         *\n");
    printf("*   4.ɾ���ڵ�         *\n");
    printf("*   5.��������         *\n");
    printf("*   6.��������         *\n");
    printf("*   7.���ҽ��         *\n");
    printf("*   8.��ת����         *\n");
    printf("*   9.�ж��Ƿ�ɻ�     *\n");
    printf("*   10.��żλ�Ի�      *\n");
    printf("*   11.�����м�ڵ�    *\n");
    //printf("*   12.ʹ����ɻ�      *\n");
    printf("************************\n");
    printf("��ѡ���ܣ�");
}
