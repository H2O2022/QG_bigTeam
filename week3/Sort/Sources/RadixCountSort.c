#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 10   // 基数为10

//基数计数排序
void radixCountSort(int arr[], int len) {
    int count[BASE];
    int* output = (int*)malloc(len * sizeof(int));
    int exp = 1;
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    while (max / exp > 0) {
        memset(count, 0, sizeof(count));
        for (int i = 0; i < len; i++) {
            count[(arr[i] / exp) % BASE]++;
        }
        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }
        for (int i = len - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
            count[(arr[i] / exp) % BASE]--;
        }
        for (int i = 0; i < len; i++) {
            arr[i] = output[i];
        }
        exp *= BASE;
    }
    free(output);
}
