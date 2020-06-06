#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int k;
int open[21];
int dp[21][21][21];

int move(int step, int x, int y)
{
	if (step > k) return 0;
	if (dp[step][x][y] != -1) return dp[step][x][y];	// dp ºÎºÐ
	return dp[step][x][y] = min(
	abs(y-open[step])+move(step+1,x,open[step]),
		abs(x-open[step])+move(step+1,y,open[step]));
}

int main(void)
{
	cin >> n;
	int c1, c2;
	cin >> c1 >> c2;
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> open[i];
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	cout << move(1, c1, c2) << endl;

	return 0;
}