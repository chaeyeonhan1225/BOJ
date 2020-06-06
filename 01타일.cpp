#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	int *dp = new int[n+1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	// Á¡È­½Ä dp[i] = dp[i-1] + dp[i-2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 15746;
	}
	cout << dp[n] << endl;

	return 0;
}