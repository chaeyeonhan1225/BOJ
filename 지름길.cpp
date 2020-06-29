#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 13

using namespace std;

int N, D;
vector < pair<int, pair<int, int>> > v;
int dp[MAX][10001];

int knapsack(int pos, int cur)
{
	if (cur == D) return 0;
	if (pos == N) return D - cur;
	if (dp[pos][cur] > 0) return dp[pos][cur];
	int ret = 0;
	if (v[pos].first == cur) {
		if (v[pos].second.first <= D) {
			ret = knapsack(pos + 1, v[pos].second.first);
			if (v[pos].second.first - cur > v[pos].second.second) {
				ret += v[pos].second.second;
			}
			else {
				ret += v[pos].second.first - cur;
			}
			if(pos<N-1)
				ret = min(ret, knapsack(pos + 1, v[pos + 1].first) + v[pos + 1].first - cur);
		}
		else {
			return D - cur;
		}
	}
	else if(v[pos].first > cur){
		ret = knapsack(pos, v[pos].first) + v[pos].first - cur;
	}
	else {
		ret = knapsack(pos + 1, cur);
	}
	
	return dp[pos][cur] = ret;
}
int main(void)
{
	cin >> N >> D;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= D; ++j) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(a, make_pair(b, c)));
	}
	
	sort(v.begin(), v.end());

	cout << knapsack(0, 0) << "\n";
	
	return 0;
}