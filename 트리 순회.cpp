#include <iostream>
#define MAX 27
using namespace std;

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ
void preorder(treePointer ptr)
{
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ
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
	// ��� �ʱ�ȭ
	for (int i = 0; i < N; ++i) {
		nodes[i].data = 'A' + i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	// ��� �Է�
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