#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare2(string &a, string &b)
{
	int a1 = 0;
	int b1 = 0;
	for (int i = 0; i < (int)a.length(); ++i) {
		if (a[i] >= '0'&&a[i] <= '9') {
			a1 += (a[i] - '0');
		}
		if (b[i] >= '0'&&b[i] <= '9') {
			b1 += (b[i] - '0');
		}
	}
	if (a1 < b1) {
		return true;
	}
	else if (a1 == b1) {
		if (a < b) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool compare1(string &a, string &b)
{
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length()) {
		return compare2(a, b);
	}
	else {
		return false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> serial;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		serial.push_back(s);
	}
	
	sort(serial.begin(), serial.end(),compare1);

	for (int i = 0; i < (int)serial.size(); ++i) {
		cout << serial[i] << "\n";
	}
	
	return 0;
}
