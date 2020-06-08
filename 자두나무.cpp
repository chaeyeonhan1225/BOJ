#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, W;
vector<int> v;
int dp[1001][3][32];	// dp[pos][cur][w]

int knapsack(int pos, int cur, int w)
{
	if (w < 0) return 0;	// �̵��� �� �ִ� Ƚ���� 0���� ������ 0�� ��ȯ
	if (pos == T) return 0;	// T�ʰ� ������ 0 ��ȯ
	if (dp[pos][cur][w] > 0) return dp[pos][cur][w];
	int ret = 0;
	if (cur == v[pos]) {	// �� �������� �ڵθ� ���� �� ����
		int temp = 1;
		if (cur == 1) temp = 2;
		ret = max(knapsack(pos + 1, cur, w) + 1, knapsack(pos + 1,temp, w - 1));
	}
	else {	// �������� �ڵθ� ���� �� ����
		if(w==0)	// ���� w == 0�� �� ���� w-1 �� ����� �� �����Ƿ� 1�� �����ָ� �ȵ�
			ret = max(knapsack(pos + 1, cur, w), knapsack(pos + 1, v[pos], w - 1));
		else
			ret = max(knapsack(pos + 1, cur, w), knapsack(pos + 1, v[pos], w - 1) + 1);
	}
	return dp[pos][cur][w] = ret;
}

int main(void)
{
	cin >> T >> W;
	// ������� ���� dp �ʱ�ȭ
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