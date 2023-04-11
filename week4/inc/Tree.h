#define _CRT_SECURE_NO_WARNINGS

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Tree {
	Node* root;
}Tree;

typedef struct Qnode {
	Node* mem;
	struct Qnode* next;
}Qnode;

typedef struct Queue {
	Qnode* head;
	Qnode* fail;
}Queue;

void menu();
Tree* init();
void prev_order(Node* node);
void in_order(Node* node);
void past_order(Node* node);
void insert(Tree* t, int val);
void search(Tree* t, int val);
void preOrder(Node* root);
void inOrder(Node* root);
void pastOrder(Node* root);
Queue* initQueue();
void enQueue(Queue* q, Node* temp);
Qnode* delQueue(Queue* q);
void levelOrder(Tree* t);
Node* deleteNode(Node* root, int key);

