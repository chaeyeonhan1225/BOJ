#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 320

using namespace std;

int n;	// 문제의 수
int m;	// 먼저 푸는 것이 좋은 문제에 대한 정보의 개수
vector<int> v[MAX];
int inDegree[MAX];
bool finished[MAX];
vector<int> result;

void topologySort()
{
	vector<int> s;
	priority_queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0) {
			q.push(-1*i);
		}
	}
	
	while (!q.empty()) {
		int x = -1 * q.top();
		q.pop();
		result.push_back(x);
		for (int j = 0; j < (int)v[x].size(); ++j) {
			int y = v[x][j];
			if (--inDegree[y] == 0) q.push(-1 * y);
		}
	}

	for (int i = 0; i < (int)result.size(); ++i) {
		cout << result[i] << " ";
	}
	cout << "\n";
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		inDegree[i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}

	topologySort();

	return 0;
}