#include <iostream>
#include <queue>
#include <utility>

#define MAX 51

using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];
int ret[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void init()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = false;
			ret[i][j] = 0;
		}
	}
}

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	int max = 0;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < n&&nx >= 0 && nx < m &&
				!visited[ny][nx] && map[ny][nx] == 'L') {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				ret[ny][nx] = ret[yy][xx]+1;
				if (max < ret[ny][nx]) max = ret[ny][nx];
			}
		}
	}
	return max;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'L') {
				init();
				int distance = bfs(i, j);
				if (max < distance) max = distance;
			}
		}
	}
	cout << max << endl;
	
	return 0;
}