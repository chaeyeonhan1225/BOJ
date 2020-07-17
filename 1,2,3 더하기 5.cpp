#include <iostream>
#define MAX 100001
using namespace std;

long long dp[MAX][5];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1][1] = 1;
	dp[1][2] = dp[1][3] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i < MAX; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (j == 1) {
				dp[i][j] = dp[i - j][2] % 1000000009 + dp[i - j][3] % 1000000009;
			}
			if (j == 2) {
				dp[i][j] = dp[i - j][1] % 1000000009 + dp[i - j][3] % 1000000009;
			}
			if (j == 3) {
				dp[i][j] = dp[i - j][1] % 1000000009 + dp[i - j][2] % 1000000009;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << "\n";
	}

	return 0;
}