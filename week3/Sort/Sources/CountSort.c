#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//¼ÆÊýÅÅÐò
void countSort(int arr[], int len){
    if (len < 1) return;
    int max = arr[0];
    for (size_t i = 1; i < len; i++)
        if (arr[i] > max) max = arr[i];

    int* count = (int*)malloc(sizeof(int) * (max + 1));
    memset(count, 0, sizeof(int) * (max + 1));

    for (size_t i = 0; i < len; i++)
        count[arr[i]]++;

    for (size_t i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    int* output = (int*)malloc(sizeof(int) * len);

    for (size_t i = 0; i < len; i++){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (size_t i = 0; i < len; i++)
        arr[i] = output[i];
    free(count);
    free(output);
}


