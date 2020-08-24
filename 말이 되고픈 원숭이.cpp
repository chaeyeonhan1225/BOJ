#include <iostream>
#include <queue>
#define MAX 201

using namespace std;

int K;
int W, H;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int horse[8][2] = {
	{-2,1}, {-1,2}, {-2,-1},{-1,-2},
	{2,1}, {1,2}, {2,-1}, {1,-2}
};
int map[MAX][MAX];
bool visited[MAX][MAX][31];

class P {
public:
	int y;
	int x;
	int d;
	int c;
	P(int _y, int _x,int _d, int _c) {
		y = _y;
		x = _x;
		d = _d;	// 이동 횟수
		c = _c; // 말처럼 움직인 횟수
	}
};

int bfs(int y, int x) {
	queue<P> q;
	q.push(P(y, x, 0, 0));
	visited[y][x][0] = true;
	while (!q.empty()) {
		int yy = q.front().y;
		int xx = q.front().x;
		int d = q.front().d;
		int c = q.front().c;
		q.pop();
		if (c < K) {	// 만약 말처럼 움직일 수 있다면
			for (int i = 0; i < 8; ++i) {
				int ny = yy + horse[i][0];
				int nx = xx + horse[i][1];
				if (ny >= 0 && ny < H && nx >= 0 && nx < W &&
					!visited[ny][nx][c + 1] && map[ny][nx] == 0) {
					if (ny == H - 1 && nx == W - 1) {	// 만약 마지막 위치에 도달한다면
						return d + 1;	// 답을 바로return 
					}
					q.push(P(ny, nx, d + 1, c + 1));
					visited[ny][nx][c + 1] = true;
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < H && nx >= 0 && nx < W &&
				!visited[ny][nx][c] && map[ny][nx] == 0) {
				if (ny == H - 1 && nx == W - 1) {
					return d + 1;
				}
				q.push(P(ny, nx, d + 1, c));
				visited[ny][nx][c] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> K;
	cin >> W >> H;	// W : x, H : y
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> map[i][j];
		}
	}
	if (W == 1 && H == 1 && map[W-1][H-1] == 0) {	// 경계조건
		cout << 0 << "\n";
	}
	else {
		cout << bfs(0, 0) << "\n";
	}
	return 0;
}