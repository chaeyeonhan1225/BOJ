#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 101

using namespace std;

vector<int> people[MAX];
int ans[MAX];
bool visited[MAX];

int bfs(int sx,int k)
{
	queue<int> q;
	q.push(sx);
	visited[sx] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : people[x]) {
			if (!visited[y]) {
				ans[y] = ans[x] + 1;
				if (y == k) return ans[y];
				q.push(y);
				visited[y] = true;
			}
		}
	}
	return -1;
}



int main(void)
{
	int n;
	cin >> n;
	int n1, n2;
	cin >> n1 >> n2;
	int m;
	cin >> m;
	
	for (int i = 1; i <= n; ++i) {
		ans[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		people[x].push_back(y);
		people[y].push_back(x);
	}

	cout << bfs(n1, n2) << endl;

	return 0;
}