#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];

void dfs(int cur)
{
	visited[cur] = true;
	for(int i = 0; i < (int)tree[cur].size(); ++i) {
		int next = tree[cur][i];
		if (!visited[next]) {
			parent[next] = cur;
			dfs(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	
	for (int i = 0; i <= N; ++i) {
		parent[i] = 0;
	}
	
	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; ++i) {
		cout << parent[i] << "\n";
	}

	return 0;
}