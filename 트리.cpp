#include <iostream>
#include <vector>
#include <queue>

#define MAX 51

using namespace std;

vector<int> tree[MAX];	
bool visited[MAX];

int bfs(int root,int k)
{
	queue<int> q;
	q.push(root);
	visited[root] = true;
	int ans = 0;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		bool flag = false;
		for (int a : tree[r]) {	// 더이상 자식 노드가 없으면 리프노드
			if (!visited[a] && a != k) {
				flag = true;
				q.push(a);
				visited[a] = true;
			}
		}
		if (!flag) ans++;
	}

	return ans;
}

int main(void)
{
	int N;
	cin >> N;
	int root = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x == -1) {
			root = i;
			continue;
		}
		tree[x].push_back(i);
	}
	int r;
	cin >> r;
	if (r == root) cout << 0 << "\n";	// root 노드 제거시, 리프 노드는 없다.
	else cout << bfs(root, r) << "\n";
	return 0;
}