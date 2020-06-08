#include <iostream>
#define MAX 51

using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool cleaned[MAX][MAX];
int cleanmap[MAX][MAX];
int ans = 0;
int nd[4] = { 3,0,1,2 };	// 반시계 방향
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

void dfs(int y, int x, int d)
{	
	cleaned[y][x] = true;
	if(cleanmap[y][x]==0)
		cleanmap[y][x] = ++ans;
	
	int k = nd[d];
	int ny = y + dir[k][0];
	int nx = x + dir[k][1];
	for (int i = 0; i < 4; ++i) {
		if (map[ny][nx] == 0 && !cleaned[ny][nx]) {
			dfs(ny, nx, k);
			return;
		}
		else {
			k = nd[k];
			ny = y + dir[k][0];
			nx = x + dir[k][1];
		}
	}
	int temp = d;
	d += 2;
	if (d > 3) d = d - 4;
	ny = y + dir[d][0];
	nx = x + dir[d][1];
	if (map[ny][nx] == 0) {
		dfs(ny, nx, temp);
	}
}

int main(void)
{
	cin >> n >> m;
	int r, c;
	int d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			cleanmap[i][j] = 0;
		}
	}

	cleaned[r][c] = true;
	visited[r][c] = true;
	dfs(r, c, d);
	
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (cleaned[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}