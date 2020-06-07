#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	vector<string> suffix;
	for (int i = 0; i < s.length(); ++i) {
		suffix.push_back(s.substr(i));
	}
	
	sort(suffix.begin(), suffix.end());

	for (int i = 0; i < suffix.size(); ++i) {
		cout << suffix[i] << "\n";
	}
	
	return 0;
}