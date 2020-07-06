#include <iostream>
#include <string>

using namespace std;

class node {
public:
	char data;
	node* prev;
	node* next;
	node(char _data) {
		data = _data;
		prev = nullptr;
		next = nullptr;
	}
};

class LinkedList {
public:
	node* head;
	node* tail;
	node* cursor;
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		cursor = head;
	}
	void insertBack(char data) {
		node* cur = new node(data);
		if (head == nullptr) {
			head = cur;
			tail = cur;
		}
		else {
			tail->next = cur;
			cur->prev = tail;
			cur->next = nullptr;
			tail = cur;
		}
		cursor = cur;
	}
	// p: ÀÎµ¦½º
	void insert(char data) {
		node* cur = new node(data);
		if (cursor == nullptr || cursor->next == nullptr) {
			insertBack(data);
		}
		else {
			cursor->next->prev = cur;
			cur->next = cursor->next;
			cursor->next = cur;
			cur->prev = cursor;
			cursor = cur;
		}
	}
	void moveLeft() {
		if (cursor != head && cursor != nullptr) {
			cursor = cursor->prev;
		}
	}

	void moveRight() {
		if (cursor != tail && cursor != nullptr) {
			cursor = cursor->next;
		}
	}

	void remove() {
		if (cursor != head && cursor != nullptr) {
			if (cursor == tail) {
				node* temp = cursor;
				cursor->prev->next = nullptr;
				tail = cursor->prev;
				cursor = cursor->prev;
				delete temp;
			}
			else {
				cursor->prev->next = cursor->next;
				cursor->next->prev = cursor->prev;
				node* temp = cursor;
				cursor = cursor->prev;
				delete temp;
			}
		}
	}
	string getans() {
		node* cur = head;
		string ret = "";
		while (cur != nullptr) {
			if (cur != head) {
				ret += cur->data;
			}
			cur = cur->next;
		}
		return ret;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		LinkedList list = LinkedList();
		list.insert('0');
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == '<') {
				list.moveLeft();
			}
			else if (s[i] == '>') {
				list.moveRight();
			}
			else if (s[i] == '-') {
				list.remove();
			}
			else {
				list.insert(s[i]);
			}
		}
		cout << list.getans() << "\n";
	}
	return 0;
}