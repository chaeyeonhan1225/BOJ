#include <iostream>
#define MAX 1001

using namespace std;

long long dp[MAX][MAX];

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = 0;
		}
	}

	dp[1][1] = 1;	// �ʱⰪ
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {  
			if (i == 1 && j == 1) continue;	// dp[1][1]�� �̹� ���� ��
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i][j - 1]) % 1000000007;	// ��ȭ��
		}
	}
	cout << dp[n][m] % 1000000007 << "\n";
	return 0;
}