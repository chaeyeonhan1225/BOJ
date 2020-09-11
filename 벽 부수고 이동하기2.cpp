#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, K;
int map[MAX][MAX];
int visited[MAX][MAX][11];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), K));
	visited[1][1][K] = true;
	while (!q.empty()) {
		int yy = q.front().first.first;
		int xx = q.front().first.second;
		int d = q.front().second;	// 벽을 깰 수 있는 횟수
		if (yy == N && xx == M) {	// 목적지에 도달하면
			return visited[yy][xx][d];
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny > 0 && ny <= N && nx > 0 && nx <= M) {
				if (map[ny][nx] == 0 && !visited[ny][nx][d]) {
					visited[ny][nx][d] = visited[yy][xx][d] + 1;
					if (ny == N && nx == M) {
						return visited[ny][nx][d];
					}
					q.push(make_pair(make_pair(ny, nx),d));
				}
				if (map[ny][nx] == 1 && !visited[ny][nx][d - 1] && d > 0) {
					visited[ny][nx][d - 1] = visited[yy][xx][d] + 1;
					if (ny == N && nx == M) {
						return visited[ny][nx][d - 1];
					}
					q.push(make_pair(make_pair(ny, nx), d - 1));
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf_s("%1d", &map[i][j]);	// 공백없이 정수 입력
		}
	}
	cout << bfs() << "\n";

	return 0;
}