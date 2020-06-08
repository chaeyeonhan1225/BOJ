#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int id = 0;
int d[MAX];
vector<int> v[MAX];
bool finished[MAX];
vector<vector<int>> SCC;
vector<int> s;

int dfs(int x)
{
	d[x] = ++id;
	int parent = d[x];
	s.push_back(x);
	
	for (int i = 0; i < v[x].size(); ++i) {
		int y = v[x][i];
		if (d[y] == 0) {
			parent = min(parent, dfs(y));
		}
		else if (!finished[y]) {
			parent = min(parent, d[y]);
		}
	}
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.back();
			scc.push_back(t);
			s.pop_back();
			finished[t] = true;
			if (t == x) {
				break;
			}
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	return parent;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= V; ++i) {
		d[i] = 0;
	}

	for (int i = 1; i <= V; ++i) {
		if (d[i] == 0) dfs(i); 
	}

	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); ++i) {
		for (int j = 0; j < SCC[i].size(); ++j) {
			cout << SCC[i][j] << " ";
		}
		cout << -1 << "\n";
	}

	return 0;
}