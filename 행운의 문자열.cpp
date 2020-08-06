#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> v;
int ans = 0;

bool isPromise(string& str, char next) {
	int k = str.size();
	if (str[k - 1] == next) {
		return false;
	} 
	return true;
}

void back_tracking(string &str,int n,char cur) {
	str.push_back(cur);
	if (str.size()==n) {
		ans++;
		return;
	}
	else {
		for (auto& next : v) {
			if (isPromise(str, next.first) && next.second > 0) {
				next.second--;
				back_tracking(str, n, next.first);
				str.pop_back();
				next.second++;
			}
		}
	}
}


int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (v.find(s[i]) == v.end()) {
			v[s[i]] = 1;
		}
		else {
			v[s[i]]++;
		}
	}
	int n = s.size();
	// &�� ����� ���� ������ �� �ִ�. �׳� auto cur�̷��� �ϸ� ����Ǽ� ���� map�� ���� ���� ���� !!
	for (auto &cur : v) {	
		string str;
		cur.second--;
		back_tracking(str,n,cur.first);
		cur.second++;
	}
	cout << ans << "\n";
	
	return 0;
}