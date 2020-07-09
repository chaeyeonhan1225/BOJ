#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> d;
int dp[10001][501];

int knapsack(int pos, int m) 
{
	if (pos == N - m) return 0;	// ���� �����ϱ� ���� ������ ��ħ������ 0�� �Ǿ����
	if (pos > N - m) return -99999999;
	if (dp[pos][m] >= 0) return dp[pos][m];
	int ret = 0;
	if (m < M) {	// ��ħ������ M���� ������ �� �޸� �� ����
		if (m > 0) {
			ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + m, 0));
		}
		else if (m == 0) {	// ��ħ������ 0�̸� �ٽ� �ٰų�, �ѹ� �� �� ������
			ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + 1, 0));
		}
	}
	else if (m == M) {	// ��ħ������ M�̸� ������ M�� ��� ��ħ������ 0���� ����������
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
		fill(dp[i], dp[i] + M + 1, -1);	// dp�迭�� -1�� �ʱ�ȭ
	}
	
	cout << knapsack(0, 0) << "\n";

	return 0;
}