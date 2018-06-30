#include<iostream>
using namespace std;

int number = 15;
//하나의 노드 정보 선언.

typedef struct node *treepointer;
typedef struct node {
	int data;
	treepointer left, right;
}node;
//전위 순회
void preorder(treepointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
//중위 순회
void inorder(treepointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}
//후위 순회
void postorder(treepointer ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	
	node nodes[15 + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0)
			nodes[i / 2].left = &nodes[i];
		else
			nodes[i / 2].right = &nodes[i];
	}
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	system("pause");
	return 0;
}