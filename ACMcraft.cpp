#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;	// 건물의 개수
		int k;	// 건물간의 건설순서규칙의 총 개수
		int inDegree[MAX];
		int time[MAX];
		int result[MAX];
		vector<int> v[MAX];
		cin >> n >> k;

		for (int i = 1; i <= n; ++i) {
			cin >> time[i];
			result[i] = time[i];
			inDegree[i] = 0;
		}

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			inDegree[b]++;
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (inDegree[i] == 0) {
				result[i] = time[i];
				q.push(i);
			}
		}

		for (int i = 1; i <= n; ++i) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < (int)v[x].size(); ++j) {
				int y = v[x][j];
				result[y] = max(result[y], result[x] + time[y]);
				if (--inDegree[y] == 0) {
					q.push(y);
				}
			}
		}
		cout << result[w] << "\n";
	}
	return 0;
}