#include <iostream>
#include <string>
#include <algorithm>
#define MAX 21
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int r, c;
int ans = 0;
char map[MAX][MAX];
bool visited[MAX][MAX];

void dfs(string& a,int y, int x)
{
	a += map[y][x];
	ans = max(ans, (int)a.size());
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < r&&nx >= 0 && nx < c) {
			if (!visited[ny][nx]&&a.find(map[ny][nx])==-1) {
				dfs(a, ny, nx);
				a.pop_back();
				visited[ny][nx] = false;
			}
		}
	}
	
}

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
		}
	}
	string a = "";
	dfs(a,0, 0);

	cout << ans << endl;
	return 0;
}