#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<char> stk;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (stk.empty()) {
				stk.push_back(s[i]);
				continue;
			}
			char top = stk.back();
			if (top == s[i]) {
				stk.pop_back();
			}
			else {
				stk.push_back(s[i]);
			}
		}
		if (stk.empty()) {
			ans++;
		}
		stk.clear();
	}

	cout << ans << "\n";
	
	return 0;
}