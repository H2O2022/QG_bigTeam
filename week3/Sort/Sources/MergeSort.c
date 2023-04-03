#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ºÏ²¢
void merge(int arr[], int tempArr[], int left, int mid, int right){
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while (l_pos <= mid && r_pos <= right){
        if (arr[l_pos] < arr[r_pos])
            tempArr[pos++] = arr[l_pos++];
        else
            tempArr[pos++] = arr[r_pos++];
    }
    while (l_pos <= mid)
        tempArr[pos++] = arr[l_pos++];
    while (r_pos <= right)
        tempArr[pos++] = arr[r_pos++];
    while (left <= right){
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int arr[], int tempArr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        msort(arr, tempArr, left, mid);
        msort(arr, tempArr, mid + 1, right);
        merge(arr, tempArr, left, mid, right);
    }
}

void MergeSort(int* arr, int len) {
    int* tempArr;
    tempArr = (int*)malloc(len * sizeof(int));
    msort(arr, tempArr, 0, len - 1);
    free(tempArr);
}

