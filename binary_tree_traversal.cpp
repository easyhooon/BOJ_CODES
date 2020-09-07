#include <iostream>

using namespace std;

int number = 15;

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr) {
	//포인터에 값이 존재할 경우
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);

	}
}

// 중위 순회
void inorder(treePointer ptr) {
	//포인터에 값이 존재할 경우
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);

	}
}

// 후위 순회
void postorder(treePointer ptr) {
	//포인터에 값이 존재할 경우
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';

	}
}

int main(void) {
	//node nodes[number + 1];
	node nodes[16];

	//초기화
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i];
		else
			nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	return 0;
}
