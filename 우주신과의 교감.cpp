#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 1001

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
	int a,b;
	double distance;
	Edge(int _a, int _b,double _distance) {
		a = _a;
		b = _b;
		distance = _distance;
	}
	bool operator <(Edge& e) {
		if (this->distance < e.distance) {
			return true;
		}
		return false;
	}
};

vector<Edge> v;
vector<pair<int, int>> graph;

int main(void)
{
	int parent[MAX];
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}

	graph.push_back(make_pair(-1, -1));

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		graph.push_back(make_pair(x, y));
	}

	v.push_back(Edge(-1, -1,-1));

	for (int i = 1; i < N; ++i) {
		int x1 = graph[i].first;
		int y1 = graph[i].second;
		for (int j = i+1; j <= N; ++j) {
			int x2 = graph[j].first;
			int y2 = graph[j].second;
			double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
			v.push_back(Edge(i, j, d));
		}
	}

	vector<Edge> temp;
	

	for (int i = 0; i < M; ++i) {
		int a1, b1;
		cin >> a1 >> b1;
		int x1 = graph[a1].first;
		int y1 = graph[a1].second;
		int x2 = graph[b1].first;
		int y2 = graph[b1].second;
		double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		unionParent(parent,a1, b1);
	}

	sort(v.begin(), v.end());

	double ans = 0;
	
	for (int i = 1; i < v.size(); ++i) {
		int s = v[i].a;
		int e = v[i].b;
		double d = v[i].distance;
		if (getParent(parent,s) == getParent(parent,e)) {
			continue;
		}
		unionParent(parent, s, e);
		ans += d;
	}

	printf("%.2lf\n", ans);

	return 0;
}