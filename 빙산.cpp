#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 301

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void init()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = false;
		}
	}
}

int ice(int y,int x)
{
	int cnt = 0;
	if (map[y - 1][x] == 0) cnt++;
	if (map[y][x - 1] == 0) cnt++;
	if (map[y + 1][x] == 0) cnt++;
	if (map[y][x + 1] == 0) cnt++;
	return cnt;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;	
	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < n&&nx >= 0 && nx < m && !visited[ny][nx] && map[ny][nx]>0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

bool iszero()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] > 0)
				return false;
		}
	}
	return true;
}

bool check()
{
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] > 0 && !visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
			if (cnt > 1) return true;
		}
	}
	return false;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	bool flag = false;
	while (!check()) {
		if (iszero()) {
			flag = true;
			break;
		}
		ans++;
		vector<pair<int, int>> zero;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] > 0) {
					int k = ice(i, j);
					if (map[i][j] <= k) {
						zero.push_back(make_pair(i,j));
					}
					else {
						map[i][j] -= k;
					}
				}
			}
		}
		for (int i = 0; i < (int)zero.size(); ++i) {
			map[zero[i].first][zero[i].second] = 0;
		}
		init();
	}
	if (!flag)
		cout << ans << endl;
	else
		cout << 0 << endl;

	return 0;
}