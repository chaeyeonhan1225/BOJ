#include <iostream>
#define MAX 101

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int dp[MAX][3];

	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	int ans = (dp[n][0] + dp[n][1] + dp[n][2])%9901;

	cout << ans << endl;

	return 0;
}