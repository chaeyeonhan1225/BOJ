#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int n;
int m;
int s;
int k = -1;
vector<int> v;
int dp[1001][101];
bool bdp[1001][101];
int ans = -1;
int cnt = 0;

int solve(int cv, int k)
{
	cnt++;
	cout << "cv: " << cv << ", k:" << k << endl;
	if (k == n-1) {
		ans = 0;
		return cv;
	}
	else if (dp[cv][k] > 0) {
		cout << "½ÇÇà" << endl;
		return dp[cv][k];
	}
	else {
		k++;
		if (cv + v[k] <= m && cv - v[k] >= 0)
			return max(dp[cv + v[k]][k] = solve(cv + v[k], k), dp[cv - v[k]][k] = solve(cv - v[k], k));
		else if (cv + v[k] <= m)
			return dp[cv + v[k]][k] = solve(cv + v[k], k);
		else if (cv - v[k] >= 0)
			return dp[cv - v[k]][k] = solve(cv - v[k], k);
		else {
			return 0;
		}
	}
}


int main(void)
{

	cin >> n >> s >> m;
	for (int i = 0; i < n; ++i) {
		int volume;
		cin >> volume;
		v.push_back(volume);
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = -1;
		}
	}

	int ret = solve(s, -1);
	if (ans == 0)
		cout << ret << endl;
	else
		cout << -1 << endl;

	cout << "cnt: " << cnt << endl;

	return 0;
}