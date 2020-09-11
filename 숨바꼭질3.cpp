#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 100001

using namespace std;

bool visited[MAX];

int bfs(int N, int K) {
	int ans = 9999999;
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		if (cur == K) {
			ans = min(ans, cnt);	
		}
		q.pop();
		int next1 = cur + 1;
		int next2 = cur - 1;
		int next3 = cur * 2;
		// 간선이 0인거 먼저 큐에 넣어야함!!
		if (next3 < MAX && !visited[next3]) {
			visited[next3] = true;
			q.push(make_pair(next3, cnt));
		}
		// -1 이 더 이득이므로 먼저 큐에 넣어야함!!
		if (next2 >= 0 && !visited[next2]) {
			visited[next2] = true;
			q.push(make_pair(next2, cnt + 1));
		}
		if (next1 < MAX && !visited[next1]) {
			visited[next1] = true;
			q.push(make_pair(next1, cnt + 1));
		} 	
	}
	return ans;
}

int main(void) {
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K) << "\n";
	
	return 0;
}