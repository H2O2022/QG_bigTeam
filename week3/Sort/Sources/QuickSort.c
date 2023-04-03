#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//øÏÀŸ≈≈–Ú
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot)
            swap(&arr[j], &arr[++i]);
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void qsort(int arr[], int low, int high){
    if (low < high){
        int mid = partition(arr, low, high);
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

void quickSort(int arr[], int len){
    qsort(arr, 0, len - 1);
}
