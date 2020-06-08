#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 101

using namespace std;

int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

class Edge {
public:
	int s, e;
	double distance;
	Edge(int _s, int _e, double _d)
	{
		s = _s;
		e = _e;
		distance = _d;
	}
	bool operator<(Edge& e)
	{
		return this->distance < e.distance;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int parent[MAX];

	vector<pair<double, double>> p;
	
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		p.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; ++i) {
		parent[i] = i;
	}
	
	vector<Edge> e;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double x = p[i].first - p[j].first;
			double y = p[i].second - p[j].second;
			double distance = sqrt(x * x + y * y);
			e.push_back(Edge(i, j, distance));
		}
	}

	sort(e.begin(), e.end());

	double ans = 0;
	for (int i = 0; i < e.size(); ++i) {
		int a = e[i].s;
		int b = e[i].e;
		double d = e[i].distance;
		if (getParent(parent, a) == getParent(parent, b)) {
			continue;
		}
		unionParent(parent, a, b);
		ans += d;
	}
	cout << ans << "\n";
	return 0;
}