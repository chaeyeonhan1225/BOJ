#include <iostream>

using namespace std;


int max_dp(int(*dp)[2], int k)
{
	int max = dp[k][0];
	for (int r = k; r >= 1; --r) {
		if (max < dp[r][0])
			max = dp[r][0];
		if (max < dp[r][1])
			max = dp[r][1];
	}
	return max;
}

int main(void)
{
	int n;
	cin >> n;
	int *g = new int[n + 1];
	int dp[10001][2];
	int max_g;

	for (int i = 1; i <= n; ++i)
		cin >> g[i];
	
	g[0] = dp[0][0] = dp[0][1] = 0;
	dp[1][0] = dp[1][1] = g[1];
	dp[2][0] = dp[1][0] + g[2];
	dp[2][1] = g[2];

	max_g = dp[2][0];
	for (int i = 3; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1] + g[i];
		dp[i][1] = max_dp(dp,i-2) + g[i];
		if (max_g < dp[i][0])
			max_g = dp[i][0];
		if (max_g < dp[i][1])
			max_g = dp[i][1];
	}

	cout << max_g << endl;

	delete[] g;
	
	return 0;
}