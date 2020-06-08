#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}

int main(void)
{
	int t;
	int s[2][1001];
	int dp[1001][2];

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j)
				cin >> s[i][j];
		}

		dp[1][0] = s[0][1];
		dp[1][1] = s[1][1];
		
		if (n > 1) {
			dp[2][0] = dp[1][1] + s[0][2];
			dp[2][1] = dp[1][0] + s[1][2];

			int max_dp = dp[2][0] > dp[2][1] ? dp[2][0] : dp[2][1];
			for (int i = 3; i <= n; ++i) {
				dp[i][0] = max(dp[i - 2][0], dp[i - 2][1], dp[i - 1][1]) + s[0][i];
				if (max_dp < dp[i][0]) max_dp = dp[i][0];
				dp[i][1] = max(dp[i - 2][0], dp[i - 2][1], dp[i - 1][0]) + s[1][i];
				if (max_dp < dp[i][1]) max_dp = dp[i][1];
			}

			cout << max_dp << endl;
		}
		else
			cout << (dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1]) << endl;
	}

	return 0;
}