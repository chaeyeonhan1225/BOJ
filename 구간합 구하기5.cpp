#include <iostream>
#define MAX 1025

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int table[MAX][MAX];
	int sum[MAX][MAX];	// 누적된 합

	for (int i = 0; i <= N; ++i) {
		sum[i][0] = 0;
		sum[0][i] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> table[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if(i > 1 && j > 1)
				sum[i][j] = sum[i-1][j] + sum[i][j-1] + table[i][j] - sum[i-1][j-1];
			if (i == 1 && j > 1)
				sum[i][j] = sum[i][j - 1] + table[i][j];
			if (j == 1 && i > 1)
				sum[i][j] = sum[i - 1][j] + table[i][j];
			if (i == 1 && j == 1)
				sum[i][j] = table[i][j];
		}
	}
	
	for (int i = 0; i < M; ++i) {
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
	return 0;
}