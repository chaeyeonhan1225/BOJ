#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	while(cin >> N){
		set<set<char>> k;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			set<char> temp;
			for (int i = 0; i < (int)s.length(); ++i) {
				temp.insert(s[i]);
			}
			k.insert(temp);
		}
		cout << k.size() << "\n";
	}
	return 0;
}