#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t = 0;

int main(void)
{
	while (1) {
		vector<char> str;
		string s = "";
		getline(cin,s);
		
		bool flag = false;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '-') {
				flag = true;
				break;
			}
		}
		if (flag)
			break;

		for (int i = 0; i < s.length(); ++i){
			if (!str.empty()) {
				if (str.back() == '{'&&s[i] == '}')
					str.pop_back();
				else
					str.push_back(s[i]);
			}
			else
				str.push_back(s[i]);
		}

		int cnt = 0;
		vector<char> a;
		for (int i = 0; i < str.size(); ++i) {
			if (!a.empty()) {
				if (a.back() == '{'&&str[i] == '{') {
					a.pop_back();
					cnt++;
				}
				else if (a.back() == '}'&&str[i] == '}') {
					a.pop_back();
					cnt++;
				}
				else {
					a.pop_back();
					cnt += 2;
				}
			}
			else {
				a.push_back(str[i]);
			}
		}
		
		cout << ++t << ". " << cnt << '\n';
	}
	
	return 0;
}