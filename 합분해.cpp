#include <iostream>

using namespace std;

int main(void)
{
	int n, k;
	int dp[201][201];

	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	for (int i = 1; i <= k; ++i) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] = dp[i][j] % 1000000000;
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}