#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, W;
vector<int> v;
int dp[1001][3][32];	// dp[pos][cur][w]

int knapsack(int pos, int cur, int w)
{
	if (w < 0) return 0;	// 이동할 수 있는 횟수가 0보다 작으면 0을 반환
	if (pos == T) return 0;	// T초가 지나면 0 반환
	if (dp[pos][cur][w] > 0) return dp[pos][cur][w];
	int ret = 0;
	if (cur == v[pos]) {	// 안 움직여야 자두를 먹을 수 있음
		int temp = 1;
		if (cur == 1) temp = 2;
		ret = max(knapsack(pos + 1, cur, w) + 1, knapsack(pos + 1,temp, w - 1));
	}
	else {	// 움직여야 자두를 먹을 수 있음
		if(w==0)	// 만약 w == 0일 때 다음 w-1 은 계산할 수 없으므로 1을 더해주면 안됨
			ret = max(knapsack(pos + 1, cur, w), knapsack(pos + 1, v[pos], w - 1));
		else
			ret = max(knapsack(pos + 1, cur, w), knapsack(pos + 1, v[pos], w - 1) + 1);
	}
	return dp[pos][cur][w] = ret;
}

int main(void)
{
	cin >> T >> W;
	// 계산하지 않은 dp 초기화
	for (int i = 0; i <= T; ++i) {
		for (int j = 0; j <= W; ++j) {
			dp[i][1][j] = -1;
			dp[i][2][j] = -1;
		}
	}
	
	for (int i = 0; i < T; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	cout << knapsack(0, 1, W) << "\n";

	return 0;
}