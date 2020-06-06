#include <iostream>
#include <queue>

#define MAX 31

using namespace std;

int L, R, C;
char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int ans[MAX][MAX][MAX];

int dist[6][3] = { {0,1,0},{0,0,1},{0,-1,0},{0,0,-1},{1,0,0},{-1,0,0} };

struct three {
	int y;
	int x;
	int z;
	three (int _z, int _y, int _x) {
		z = _z;
		y = _y;
		x = _x;
	};
	three() {
		z = 0;
		y = 0;
		x = 0;
	};
	void push(int _z, int _y, int _x) {
		z = _z;
		y = _y;
		x = _x;
	};
};

void init()
{
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < R; ++j) {
			for (int k = 0; k < C; ++k) {
				ans[i][j][k] = 0;
				visited[i][j][k] = false;
			}
		}
	}
}
void bfs(int z, int y, int x)
{
	queue<three> q;
	visited[z][y][x] = true;
	q.push(three(z, y, x));
	int ret = -1;
	while (!q.empty()) {
		int zz = q.front().z;
		int yy = q.front().y;
		int xx = q.front().x;
		if (map[zz][yy][xx] == 'E') {
			ret = ans[zz][yy][xx];
			break;
		}
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nz = zz + dist[i][0];
			int ny = yy + dist[i][1];
			int nx = xx + dist[i][2];
			if (nz >= 0 && nz < L&&ny >= 0 && ny < R&&nx >= 0 && nx < C) {
				if (!visited[nz][ny][nx]&&map[nz][ny][nx]!='#') {
					q.push(three(nz, ny, nx));
					visited[nz][ny][nx] = true;
					ans[nz][ny][nx] = ans[zz][yy][xx] + 1;
				}
			}
		}
	}
	if (ret > 0) {
		cout << "Escaped in " << ret << " minute(s)." << endl;
	}
	else {
		cout << "Trapped!" << endl;
	}
}

int main(void)
{
	while (1) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			break;

		init();
		
		three start;

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					cin >> map[i][j][k];
					
					if (map[i][j][k] == 'S')
						start.push(i, j, k);
				}
			}
		}

		bfs(start.z, start.y, start.x);
		
	}
	
	return 0;
}