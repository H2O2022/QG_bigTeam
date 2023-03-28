#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
	StackNode* s = NULL;
	menu();

	while (1) {
		//printf("22222222222\n");
		int f = 0;
		printf("Please choose the function");
		printf("-->");
		int t = scanf("%d", &f);
		if (t == 1) {
			if (f == 0) {
				printf("Goodbye\n");
				break;
			}
			else if (f == 1) {
				if (s == NULL) {
					s = initLStack();
					printf("Success\n");
				}
				else {
					printf("Stack has initialized\n");
				}
			}
			else {
				if (s == NULL) {
					printf("Stack is not initialized.\n");
				}
				else {
					if (f == 2) {
						isEmptyLStack(s);
					}
					else if (f == 3) {
						getTopLStack(s);
					}
					else if (f == 4) {
						clearLStack(s);
						printStack(s);
					}
					else if (f == 5) {
						destroyLStack(s);
					}
					else if (f == 6) {
						LStackLength(s);
						printStack(s);
					}
					else if (f == 7) {
						int d = 0;
						printf("Please input the data of node.\n");
						printf("-->");
						int e = scanf("%d", &d);
						if (e == 1) {
							pushLStack(s, d);
							printStack(s);
						}
						else {
							printf("Please input a numble.\n");
						}
					}
					else if (f == 8) {
						popLStack(s);
						printStack(s);
					}
					else {
						printf("Please input correct command\n");
					}
				}
			}
		}
	}
}