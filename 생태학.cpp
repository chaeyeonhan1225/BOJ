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
			tree[name] = 1;	// 없으면 1로 초기화
		}
		else {
			tree[name]++;	// 있으면 추가
		}
		cnt++;
	}
	map<string, int>::iterator it;
	for (it = tree.begin(); it != tree.end(); ++it) {
		cout.precision(4);	// 소수점 넷째자리까지 출력
		cout << (*it).first << " " << fixed << (double)100*(*it).second/cnt << "\n";
	}

	return 0;
}