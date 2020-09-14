#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 999999999

using namespace std;

vector<pair<int, int>> graph[MAX];

void dijkstra(int n,int start,int end) {
	priority_queue<pair<int, int>> pq;
	int d[MAX];
	int p[MAX];
	for (int i = 1; i <= n; ++i) {
		d[i] = INF;
		p[i] = -1;
	}
	d[start] = 0;
	p[start] = start;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -1 * pq.top().first;
		pq.pop();
		if (d[cur] < distance) continue;
		for (int i = 0; i < (int)graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-1 * nextDistance, next));
				p[next] = cur;	// 이전 노드를 저장
			}
		}
	}
	int k = end;
	int cnt = 0;
	vector<int> route;
	route.push_back(end);
	while (k != start) {	// 노드 역추적
		route.push_back(p[k]);
		k = p[k];
	}
	cout << d[end] << "\n";
	cout << route.size() << "\n";
	for (int i = route.size() - 1; i >= 0; --i) {	// 최단경로 출력
		cout << route[i] << " ";
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	int start, end;
	cin >> start >> end;
	dijkstra(n, start,end);
	
	return 0;
}