#include <iostream>
#include <vector>

using namespace std;

int getParent(vector<int> &parent,int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G;	// 게이트의 수
	int P;	// 비행기의 수
	cin >> G >> P;

	vector<int> g;
	g.push_back(0);
	vector<int> parent;
	parent.push_back(0);
	for (int i = 0; i < P; ++i) {
		int a;
		cin >> a;
		g.push_back(a);
	}

	for (int i = 1; i <= G; ++i) {
		parent.push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= P; ++i) {
		int k = getParent(parent, g[i]);
		if (k == 0) {
			break;
		}
		parent[k] = getParent(parent,k-1);
		cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
}