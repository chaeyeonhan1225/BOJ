#include <iostream>
#include <algorithm>
#define MAX 101

using namespace std;

int N;	// N: 주문의 수
int M, K;	// M: 치즈버거 개수, K: 감자튀김 개수
int cheese[MAX];
int ff[MAX];
int dp[MAX][301][301];

int knapsack(int pos, int c, int f)
{
	if (pos == N) return 0;
	if (dp[pos][c][f] >= 0) return dp[pos][c][f];
	int ret = 0;
	if (cheese[pos] <= c && ff[pos] <= f) {
		ret = knapsack(pos + 1, c - cheese[pos], f - ff[pos]) + 1;
	}
	ret = max(ret, knapsack(pos + 1, c, f));
	return dp[pos][c][f] = ret;
}

int main(void)
{
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k <= K; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cin >> cheese[i] >> ff[i];
	}

	cout << knapsack(0, M, K) << "\n";

	return 0;
}