#include <iostream>
#define MAX 251
#define INF 99999999

using namespace std;

int a[MAX][MAX];

void floydWarshall(int Y)
{
	for (int k = 1; k <= Y; ++k) {
		for (int i = 1; i <= Y; ++i) {
			for (int j = 1; j <= Y; ++j) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];

				}
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Y;
	int m;
	cin >> Y >> m;

	for (int i = 1; i <= Y; ++i) {
		for (int j = 1; j <= Y; ++j) {
			a[i][j] = INF;
		}
		a[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, b;
		cin >> u >> v >> b;
		if (b == 0) {
			a[u][v] = 0;
			a[v][u] = 1;
		}
		else {
			a[u][v] = 0;
			a[v][u] = 0;
		}
	}

	floydWarshall(Y);

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int s, e;
		cin >> s >> e;
		cout << a[s][e] << "\n";
	}

	return 0;
}