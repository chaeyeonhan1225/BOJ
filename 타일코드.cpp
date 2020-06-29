#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	long long int dp[31];
	long long int dp1[31];	// ¿ÏÀü ´ëÄª
	long long int dp2[31];

	dp1[0] = 0;
	dp1[1] = 1;
	dp1[2] = 3;
	dp1[3] = 1;
	dp1[4] = 5;

	for (int i = 5; i <= n; ++i) {
		dp1[i] = dp1[i - 2] + 2 * dp1[i - 4];
	}
	

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;

	for (int i = 4; i <= n; ++i) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}

	dp2[0] = 0;
	for (int i = 1; i <= 31; ++i) {
		dp2[i] = (dp[i] - dp1[i]) / 2 + dp1[i];
	}
	cout << dp2[n] << endl;

	return 0;
}