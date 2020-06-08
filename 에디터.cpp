#include <iostream>
#include <string>

using namespace std;

template <typename T>
class node {
public:
	T data;
	node<T>* next;
	node<T>* prev;
	node<T>(T _data) 
	{
		data = _data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename T>
class DLinkedList {
private:
	node<T>* head;
	node<T>* tail;
	node<T>* crnt;
public:
	DLinkedList()
	{
		head = tail = crnt = nullptr;
	}
	void insert_back(T _data)
	{
		node<T>* newNode = new node<T>(_data);
		if (head == nullptr) {
			head = newNode;
			crnt = newNode;
			tail = new node<T>(NULL);
			head->next = tail;
			head->prev = nullptr;
			tail->prev = newNode;
			tail->next = nullptr;
		}
		else {
			newNode->prev = tail->prev;
			tail->prev->next = newNode;
			tail->prev = newNode;
			newNode->next = tail;
			crnt = newNode;
		}
	}
	void insert(T _data)
	{
		node<T>* newNode = new node<T>(_data);
		if (head == nullptr) {
			head = newNode;
			crnt = newNode;
			head->next = tail;
			head->prev = nullptr;
			tail->prev = newNode;
			tail->next = nullptr;
		}
		else {	
			if (crnt == tail) {
				insert_back(_data);
			}
			else {
				node<T>* temp = crnt->next;
				newNode->prev = crnt;
				newNode->next = crnt->next;
				crnt->next = newNode;
				temp->prev = newNode;
				crnt = crnt->next;
			}
		}
	}
	void remove()
	{
		if(head!=nullptr&&head->next!=tail&&crnt!=head) {
			node<T>* delnode = crnt;
			crnt->prev->next = crnt->next;
			crnt->next->prev = crnt->prev;
			crnt = crnt->prev;
			delete delnode;
		}
	}
	void print_crnt()
	{
		if (crnt != nullptr) {
			cout << (*crnt).data << endl;
		}
	}
	void print()
	{
		node<T>* p = head;
		while (p != tail) {
			cout << (*p).data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void move_left()
	{
		if (crnt != head) {
			crnt = crnt->prev;
		}
	}
	void move_right()
	{
		if (crnt->next!= tail) {
			crnt = crnt->next;
		}
	}
	void print_answer()
	{
		if (head->next != nullptr) {
			node<T>* p = head->next;
			while (p != tail) {
				cout << (*p).data;
				p = p->next;
			}
			cout << endl;
		}
		else {
			cout << "" << endl;
		}
		
	}
};
int main(void)
{
	DLinkedList<char> list;
	string str;
	cin >> str;
	list.insert_back('-');
	for (int i = 0; i < (int)str.length(); ++i) {
		list.insert_back(str[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		char order;
		cin >> order;
		if (order == 'P') {
			char x;
			cin >> x;
			list.insert(x);
		}
		else if (order == 'L') {
			list.move_left();
		}
		else if (order == 'D') {
			list.move_right();
		}
		else {
			list.remove();
		}
	}
	list.print_answer();

	return 0;
}