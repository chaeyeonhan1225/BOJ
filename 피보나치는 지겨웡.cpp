#include <iostream>

using namespace std;

long long dp[51];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		dp[i] = -1;
	}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
	}
	cout << dp[n] << "\n";

	return 0;
}