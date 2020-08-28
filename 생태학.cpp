#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	string name;
	map<string, int> tree;
	while (getline(cin, name)) {
		if (tree.find(name) == tree.end()) {
			tree[name] = 1;	// ������ 1�� �ʱ�ȭ
		}
		else {
			tree[name]++;	// ������ �߰�
		}
		cnt++;
	}
	map<string, int>::iterator it;
	for (it = tree.begin(); it != tree.end(); ++it) {
		cout.precision(4);	// �Ҽ��� ��°�ڸ����� ���
		cout << (*it).first << " " << fixed << (double)100*(*it).second/cnt << "\n";
	}

	return 0;
}