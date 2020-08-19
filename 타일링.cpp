#include <iostream>
#include <string>
#define MAX 251

using namespace std;

// Å« ¼ö °ö¼À
string mul_bigInteger(string& a, int m) {
	int aSize = a.size();
	int c = 0;
	string rans = "";
	for (int i = aSize - 1; i >= 0; --i) {
		int ret = (a[i] - '0') * m;
		rans += ((ret + c) % 10) + '0';
		c = ret / 10;
	}
	if (c > 0) {
		rans += c + '0';
	}
	string ans = "";
	int rSize = rans.size();
	for (int i = rSize - 1; i >= 0; --i) {
		ans += rans[i];
	}
	return ans;
}

// Å« ¼ö µ¡¼À
string plus_bigInteger(string& a, string& b) {
	int aSize = a.size();
	int bSize = b.size();
	string rans = "";
	int c = 0;
	while (aSize > 0 || bSize > 0) {
		int a1 = 0;
		int b1 = 0;
		if (aSize > 0) {
			a1 = a[--aSize] - '0';
		}
		if (bSize > 0) {
			b1 = b[--bSize] - '0';
		}
		int ret = a1 + b1 + c;
		rans += (ret % 10) + '0';
		c = ret / 10;
	}
	if (c > 0) {
		rans += c + '0';
	}
	int rSize = rans.size();
	string ans = "";
	for (int i = rSize - 1; i >= 0; --i) {
		ans += rans[i];
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string dp[MAX];
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	while (cin >> n) {
		for (int i = 3; i <= n; ++i) {
			string a = mul_bigInteger(dp[i - 2], 2);	// Á¡È­½Ä dp[i] = 2 * dp[i-2] + dp[i-1]
			string b = dp[i - 1];
			dp[i] = plus_bigInteger(a, b);
		}
		cout << dp[n] << "\n";
	}
	return 0;
}