#include <iostream>
#include <vector>
#define MAX 501
#define INF 2000001

using namespace std;

vector<int> h[MAX];
int d[MAX][MAX];

int floydWarshall(int n)
{
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][k] + d[k][j] <= d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int cnt = 0;
	for (int k = 1; k <= n; ++k) {
		int i;
		for (i = 1; i <= n; ++i) {
			if (k == i) continue;
			if (d[k][i] == INF && d[i][k] == INF)
				break;
			if (d[k][i] < INF && d[i][k] < INF)
				break;
		}
		if (i > n) {
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		h[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)h[i].size(); ++j) {
			int y = h[i][j];
			d[i][y] = 1;
		}
	}

	cout << floydWarshall(n) << "\n";

	return 0;
}