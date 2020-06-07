#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> op;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	vector<char> expression;	// 연산자 스택
	vector<char> temp;			// 괄호 스택
	vector<char> ret;			// 결과

	// 연산자 우선순위
	op['*'] = 0;
	op['/'] = 0;
	op['+'] = 1;
	op['-'] = 1;


	for (int i = 0; i < (int)str.length(); ++i) {
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
			if (temp.empty()) {
				temp.push_back(str[i]);
			}
			else {
				// 연산자 우선순위 정리
				char c = temp.back();
				while (c != '(' && op[c] <= op[str[i]]) {
					ret.push_back(c);
					temp.pop_back();
					if (temp.empty()) break;
					c = temp.back();
				}
				temp.push_back(str[i]);
			}
		}
		else if (str[i] == '(') {	// 괄호 라면
			temp.push_back(str[i]);
		}
		else if (str[i] == ')') {
			char top = temp.back();
			while (top!='(') {
				ret.push_back(top);
				temp.pop_back();
				top = temp.back();
			}
			temp.pop_back();
		}
		else {
			// 괄호도, 연산자가 아니라면
			ret.push_back(str[i]);
		}
	}

	while (!temp.empty()) {
		char a = temp.back();
		ret.push_back(a);
		temp.pop_back();
	}

	for (int i = 0; i < (int)ret.size(); ++i) {
		cout << ret[i];
	}
	cout << "\n";
	return 0;
}