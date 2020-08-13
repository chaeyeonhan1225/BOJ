#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fibonnaci;

// Å« ¼ö µ¡¼À
string big_integer(string& a, string& b) {
	int aSize = a.size();
	int bSize = b.size();
	string rans = "";
	int c = 0;
	while (aSize > 0 || bSize > 0) {
		int k1 = 0;
		int k2 = 0;
		if (aSize > 0) {
			k1 = a[--aSize] - '0';
		}
		if (bSize > 0) {
			k2 = b[--bSize] - '0';
		}
		int ret = k1 + k2 + c;
		c = ret / 10;
		ret %= 10;
		rans += ret + '0';
	}
	if (c > 0) {
		rans += c + '0';
	}
	string ans = "";
	for (int i = (int)rans.size() - 1; i >= 0; --i) {
		ans += rans[i];
	}
	return ans;
}

int main(void) {
	int n;
	cin >> n;
	fibonnaci.push_back("0");
	fibonnaci.push_back("1");	// fibonnaci[1] = 1
	fibonnaci.push_back("1");	// fibonnaci[2] = 1
	for (int i = 3; i <= n; ++i) {
		fibonnaci.push_back(big_integer(fibonnaci[i - 1], fibonnaci[i - 2]));
	}
	cout << fibonnaci[n] << "\n";
	return 0;
}
