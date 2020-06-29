#include <iostream>

using namespace std;

class Node {
	friend class SnailList;
	Node *next;
	int data;
	int num;
public:
	Node()
	{
		next = nullptr;
		data = 0;
	}
	Node(Node *_next,int _data)
	{
		next = _next;
		data = _data;
	}

};

class SnailList {
	Node *head;
	Node *crnt;

public:
	SnailList()
	{
		head = crnt = nullptr;
	}
	void Insertback(int data)
	{
		Node *n = new Node(nullptr, data);
		if (head == nullptr) {
			head = crnt = n;
		}
		else {
			crnt->next = n;
			crnt = n;
		}
	}
	Node* search(int v)const
	{
		Node *p = head;//head가 0번
		int num = 0;
		while (num!=v) {
			p = p->next;
			num++;
		}
		return p;
	}
	
	void MakeSnail(int v)
	{
		Node *p = crnt;	//N번째 노드
		crnt->next = search(v-1);
	}

	void printdata(int n)const
	{	
		cout << search(n)->data << endl;
	}
};

int main(void)
{
	int n;
	int m;
	int v;
	cin >> n >> m >> v;
	SnailList list;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		list.Insertback(a);
	}

	list.MakeSnail(v);
	
	for (int i = 0; i < m; ++i) {
		int ch;
		cin >> ch;
		if (ch > n)
			ch -= n;
		ch = ch % (n - v+2);
		list.printdata(ch);
	}

	return 0;
}