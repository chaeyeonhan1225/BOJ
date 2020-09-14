#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 99999999

using namespace std;

vector<pair<int,int>> graph[MAX];
int d[MAX][MAX];

// 다익스트라
void dijkstra(int N, int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	d[start][start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -1 * pq.top().first;
		pq.pop();
		if (d[start][cur] < distance) continue;
		for (int i = 0; i < (int)graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int nextDistance = graph[cur][i].second + distance;
			if (nextDistance < d[start][next]) {
				d[start][next] = nextDistance ;
				pq.push(make_pair(-1 * nextDistance, next));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {	
			graph[i].clear();	// 그래프 초기화
			fill(d[i], d[i] + MAX, INF);	// 거리 배열 초기화
		}
		for (int i = 0; i < M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		int K;
		cin >> K;
		int ans[MAX];
		int min_ans = INF;
		int room = 0;
		fill(ans, ans + MAX, 0);
		for (int i = 0; i < K; ++i) {
			int c;
			cin >> c;
			dijkstra(N, c);
			// 거리의 합
			for (int i = 1; i <= N; ++i) {
				ans[i] += d[c][i];
				
			}
			
		}
		// 거리의 합이 제일 작은 방 번호를 구한다.
		for (int i = 1; i <= N; ++i) {
			if (ans[i] < min_ans) {
				room = i;
				min_ans = ans[i];
			}
			else if (ans[i] == min_ans) {	// 작은 방 번호 출력
				continue;
			}
		}
		cout << room << "\n";
	}
	return 0;
}