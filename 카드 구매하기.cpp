#include <iostream>

using namespace std;

int max_dp(int (*dp)[101],int n)
{
	int max = dp[n][1];
	for (int i = 1; i <= n; ++i)
		if (max < dp[n][i])
			max = dp[n][i];
	return max;
}

int main(void)
{
	int n;
	int p[1001];
	int dp[101][101];

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	dp[1][1] = p[1];
	dp[2][1] = dp[1][1] + dp[1][1];
	dp[2][2] = p[2];

	for (int i = 3; i <= n; ++i)
		dp[i][i] = p[i];

	for (int i = 3; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i][j] = max_dp(dp,j) + max_dp(dp,i-j);
		}
	}

	cout << max_dp(dp, n) << endl;
	
	return 0;
}