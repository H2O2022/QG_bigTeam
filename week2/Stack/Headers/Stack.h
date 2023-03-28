#define _CRT_SECURE_NO_WARNINGS

typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode;

void menu();
StackNode* initLStack();
void isEmptyLStack(StackNode* s);
void getTopLStack(StackNode* s);
void clearLStack(StackNode* s);
void destroyLStack(StackNode* s);
void LStackLength(StackNode* s);
void pushLStack(StackNode* s, int val);
void popLStack(StackNode* s);
void printStack(StackNode* s);