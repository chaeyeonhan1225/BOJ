#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

class P {
public:
	int y;
	int x;
	int d;
	int cnt;
	P(int _y, int _x, int _d, int _cnt) {
		y = _y;
		x = _x;
		d = _d;
		cnt = _cnt;
	}
};

int M, N;
int map[MAX][MAX];
bool visited[MAX][MAX][5];

int dir[5][2] = {
	{0,0},
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
};

int bfs(int sy,int sx,int sd,int dy,int dx,int dd) {
	queue<P> q;
	q.push(P(sy, sx, sd, 0));
	visited[sy][sx][sd] = true;
	if (sy == dy && sx == dx && sd == dd) {
		return 0;
	}
	while (!q.empty()) {
		int yy = q.front().y;
		int xx = q.front().x;
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		// 명령 1
		for (int i = 1; i <= 3; ++i) {	// k는 1부터 3까지
			int ny = yy + dir[d][0] * i;
			int nx = xx + dir[d][1] * i;
			// 가는 길이 전부다 0이어야 갈 수 있다.
			bool flag = true;
			for (int j = 1; j <= i; ++j) {
				int y = yy + dir[d][0] * j;
				int x = xx + dir[d][1] * j;
				if (map[y][x] == 1) {
					flag = false;
					break;
				}
			}
			if (ny > 0 && ny <= M && nx > 0 && nx <= N
				&& !visited[ny][nx][d] && flag) {
				if (ny == dy && nx == dx && d == dd) {
					return cnt + 1;
				}
				visited[ny][nx][d] = true;
				q.push(P(ny, nx, d, cnt + 1));
			}
		}
		// 명령 2
		int ndl = 0;
		int ndr = 0;
		if (d == 1) {
			ndl = 4;
			ndr = 3;
		}
		else if (d == 2) {
			ndl = 3;
			ndr = 4;
		}
		else if (d == 3) {
			ndl = 1;
			ndr = 2;
		}
		else {
			ndl = 2;
			ndr = 1;
		}
		
		if (!visited[yy][xx][ndl]) {
			if (yy == dy && xx == dx && ndl == dd) {
				return cnt + 1;
			}
			visited[yy][xx][ndl] = true;
			q.push(P(yy, xx, ndl, cnt + 1));
		}
		
		if (!visited[yy][xx][ndr]) {
			if (yy == dy && xx == dx && ndr == dd) {
				return cnt + 1;
			}
			visited[yy][xx][ndr] = true;
			q.push(P(yy, xx, ndr, cnt + 1));
		}
	}
	return -1;
}

int main(void) {
	
	cin >> M >> N;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	int sy, sx, sd;
	int dy, dx, dd;
	cin >> sy >> sx >> sd;
	cin >> dy >> dx >> dd;
	cout << bfs(sy, sx, sd, dy, dx, dd) << "\n";

	return 0;
}