#include <iostream>
#define MAX 27
using namespace std;

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;

// 전위 순회
void preorder(treePointer ptr)
{
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

// 후위 순회
void postorder(treePointer ptr)
{
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}

int main(void)
{
	int N;
	cin >> N;
	node nodes[MAX];
	// 노드 초기화
	for (int i = 0; i < N; ++i) {
		nodes[i].data = 'A' + i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	// 노드 입력
	for (int i = 0; i < N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		int k = a - 'A';
		int left, right;
		left = b - 'A';
		right = c - 'A';
		if (left > 0) {
			nodes[k].leftChild = &nodes[left];
		}
		if (right > 0) {
			nodes[k].rightChild = &nodes[right];
		}
	}

	preorder(&nodes[0]);
	cout << "\n";
	inorder(&nodes[0]);
	cout << "\n";
	postorder(&nodes[0]);
	cout << "\n";

	return 0;
}