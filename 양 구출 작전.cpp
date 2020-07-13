#include <iostream>
#include <vector>
#define MAX 123457

using namespace std;

vector<int> graph[MAX];

long long dfs(vector<pair<char, int>> &island,int cur)
{
	int s = graph[cur].size();
	if (s == 0) {
		if (island[cur].first == 'S') {
			return island[cur].second;
		}
		else {
			return  0;
		}
	}
	long long ret = 0;
	for (int i = 0; i < s; ++i) {
		int next = graph[cur][i];
		ret += dfs(island, next);
	}
	if (island[cur].first == 'W') {
		ret -= island[cur].second;
		if (ret < 0) ret = 0;
	}
	else {
		ret += island[cur].second;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<char, int>> island(N + 1);
	island[1] = make_pair('S', 0);
	for (int i = 2; i <= N; ++i) {
		char t;
		cin >> t;
		int a, p;
		cin >> a >> p;
		island[i] = make_pair(t, a);
		graph[p].push_back(i);
	}
	cout << dfs(island, 1) << "\n";

	return 0;
}