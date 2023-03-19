#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// main����
int main() {
    ListNode* head = NULL;
    while (1) {
        int f1;
        menu();
        scanf("%d", &f1);
        if (f1 == 0) {//��������
            printf("goodbye\n");
            break;
        }
        else if (f1 == 1) {//��ʼ������
            head = initList();
            printf("�����ʼ�����\n");
        }
        else if (f1 == 2) {//��������
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else {
                createList(head);
            }
        }
        else if (f1 == 3) {//����ڵ�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                printList(head);
                int index, value;
                printf("��ѡ����Ҫ�ڵڼ����ڵ��������ݣ�\n");
                scanf("%d", &index);
                printf("��������Ҫ����Ľڵ�ֵ��\n");
                scanf("%d", &value);
                insertList(head, index, value);
            }
        }
        else if (f1 == 4) {//ɾ���ڵ�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                printList(head);
                printf("��ѡ����Ҫɾ���ڼ����ڵ㣺");
                int index;
                scanf("%d", &index);
                deleteList(head, index);
                printf("ɾ���ڵ�ɹ�\n");
            }
        }
        else if (f1 == 5) {//��������
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                printList(head);
            }
        }
        else if (f1 == 6) {//��������
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                destroyList(&head);
                printf("���ٳɹ�\n");
            }
        }
        else if (f1 == 7) {//���ҽڵ�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                printf("��������Ҫ���ҵ�ֵ��");
                int value;
                scanf("%d", &value);
                searchList(head, value);
            }
        }
        else if (f1 == 8) {//��ת����
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                reverseList(head);
                printf("��ת����ɹ�\n");
            }
        }
        else if (f1 == 9) {//�ж��Ƿ�ɻ�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                int ans = isloopList(head);
                if (ans == 1) {
                    printf("����ɻ�\n");
                }
                else {
                    printf("�����ɻ�\n");
                }
            }
        }
        else if (f1 == 10) {//��żλ�Ի�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                reverseEvenList(head);
                printf("��ż�Ի��ɹ�\n");
            }
        }
        else if (f1 == 11) {//�����м�ڵ�
            if (head == NULL) {
                printf("���ȳ�ʼ������\n");
            }
            else if (head->next == NULL) {
                printf("����Ϊ�գ�������ӽڵ�\n");
            }
            else {
                int ans;
                ans = findMidList(head);
                printf("�м�ڵ��ǵ�%d��\n", ans);
            }
        }
        //else if (f1 == 12) {
        //    int index;
        //    printList(head);
        //    printf("��������������ĩ��ָ��ڼ����ڵ㣺");
        //    scanf("%d", &index);
        //    makeLoopList(head, index);
        //}
        else {
            printf("���벻�淶\n");
        }
    }
    return 0;
}
