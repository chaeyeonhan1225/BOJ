#include <iostream>
#include <queue>
#include <utility>

#define MAX 251

using namespace std;

int R, C;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ansv = 0;
int ansk = 0;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int vv = 0;	// 늑대의 수
	int kk = 0;	// 양의 수	
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		if (map[yy][xx] == 'v') vv++;
		if (map[yy][xx] == 'k') kk++;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < R&&nx >= 0 && nx < C && !visited[ny][nx]
				&& map[ny][nx] != '#') {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
	if (kk > vv) {
		ansk += kk;
	}
	else {
		ansv += vv;
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (!visited[i][j] && map[i][j] != '#') {
				bfs(i, j);
			}
		}
	}
	
	cout << ansk << " " << ansv << "\n";
	
	return 0;
}