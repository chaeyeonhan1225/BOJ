#include <iostream>
#include <queue>

#define MAX 101
using namespace std;

int N, M, T;
int map[MAX][MAX];
bool visited[MAX][MAX][2];	// 0: 그람이 없는 경우 1: 그람이 있는 경우
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 100001;

class P {
public:
	int y;
	int x;
	bool gram;
	int t;
	P(int _y, int _x, bool _gram,int _t) {
		y = _y;
		x = _x;
		gram = _gram;
		t = _t;
	}
};

int bfs() {
	queue<P> q;
	q.push(P(0, 0, false,0));
	visited[0][0][0] = true;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		
		bool gram = q.front().gram;
		int t = q.front().t;
		if (y == N - 1 && x == M - 1) {
			if (ans > t) ans = t;
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (gram) {	// 그람이 있으면 벽을 뚫고 갈 수 있다.
					if (map[ny][nx] == 1 && !visited[ny][nx][1]) {
						q.push(P(ny, nx, true, t + 1));
						visited[ny][nx][1] = true;
					}
					if (map[ny][nx] == 0 && !visited[ny][nx][1]) {
						q.push(P(ny, nx, true, t + 1));
						visited[ny][nx][1] = true;
					}
				}
				else {
					if (map[ny][nx] != 1 && !visited[ny][nx][0]) {
						if (map[ny][nx] == 2) {	// 그람을 발견한 경우
							q.push(P(ny, nx, true, t + 1));
							visited[ny][nx][0] = true;
						}
						else {
							q.push(P(ny, nx, false , t + 1));
							visited[ny][nx][0] = true;
						}
					}
				}
			
			}
		}
	}
	return ans;
}

int main(void) {
	cin >> N >> M >> T;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	int ret = bfs();
	if (ret <= T) {	// 시간 내에 구할 수 있으면
		cout << ret << "\n";
	}
	else {
		cout << "Fail" << "\n";
	}
	return 0;
}