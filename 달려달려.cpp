#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> d;
int dp[10001][501];

int knapsack(int pos, int m) 
{
	if (pos == N - m) return 0;	// 수업 시작하기 전에 무조건 지침지수가 0이 되어야함
	if (pos > N - m) return -99999999;
	if (dp[pos][m] >= 0) return dp[pos][m];
	int ret = 0;
	if (m < M) {	// 지침지수가 M보다 작으면 더 달릴 수 있음
		if (m > 0) {
			ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + m, 0));
		}
		else if (m == 0) {	// 지침지수가 0이면 다시 뛰거나, 한번 더 쉴 수있음
			ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + 1, 0));
		}
	}
	else if (m == M) {	// 지침지수가 M이면 무조건 M번 쉬어서 지침지수를 0으로 만들어줘야함
		ret = knapsack(pos + m, 0);
	}

	return dp[pos][m] = ret;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		d.push_back(a);
		fill(dp[i], dp[i] + M + 1, -1);	// dp배열을 -1로 초기화
	}
	
	cout << knapsack(0, 0) << "\n";

	return 0;
}