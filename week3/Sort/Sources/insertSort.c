#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//≤Â»Î≈≈–Ú
void insertSort(int arr[], int n) {
	int a = 0;
	int j = 0;
	for (int i = 0; i < n-1; i++) {
		a = arr[i + 1];
		for (j = i; j >= 0; j--) {
			if (arr[j] > a) {
				arr[j + 1] = arr[j];
				arr[j] = a;
			}
			else {
				break;
			}
		}
	}
}
