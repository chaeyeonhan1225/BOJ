#include <iostream>
#define MAX 17

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dp[MAX][MAX][3];
int n;
int cnt = 0;

int pipe[3][2][2] = {
	{{2,2},{0,0}},	// 가로
	{{2,0},{2,0}},	// 세로
	{{2,0},{0,2}}	// 대각선
};

bool setpipe(int y,int x,int status)
{
	if (status == 0) {
		if (x >= n || x + 1 >= n || map[y][x+1]==1)
			return false;
		else
			return true;
	}
	else if (status == 1) {
		if (y >= n || y + 1 >= n|| map[y+1][x]==1)
			return false;
		else
			return true;
	}
	else {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				int ny = y + i;
				int nx = x + j;

				if (ny >= n || nx >= n) {
					return false;
				}
				if (map[ny][nx] == 1) {
					return false;
				}
			}
		}
		return true;
	}
	
}

void delpipe(int y, int x)
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (map[y + i][x + j] == 1)
				continue;
			map[y + i][x + j] = 0;
		}
	}
	map[y][x] = 2;
}

void dfs(int y, int x, int status)
{
	if (setpipe(y, x, status)) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (map[y + i][x + j] == 1) continue;
				map[y + i][x + j] = pipe[status][i][j];
			}
		}
		int yy = y;
		int xx = x;
		if (status == 0) xx++;
		else if (status == 1) yy++;
		else {
			xx++; 
			yy++;
		}
		if (yy == n - 1 && xx == n - 1) {
			cnt++;
			delpipe(yy, xx);
			return;
		}
		else {
			if (status == 0) {
				dfs(yy, xx, 0);
				delpipe(yy, xx);
				dfs(yy, xx, 2);
				delpipe(yy, xx);
			}
			else if (status == 1) {
				dfs(yy, xx, 1);
				delpipe(yy, xx);
				dfs(yy, xx, 2);
				delpipe(yy, xx);
			}
			else {
				dfs(yy, xx, 0);
				delpipe(yy, xx);
				dfs(yy, xx, 1);
				delpipe(yy, xx);
				dfs(yy, xx, 2);
				delpipe(yy, xx);
			}
		}

	}
	else {
		return;
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			
		}
	}

	dfs(0, 0, 0);
	cout << cnt << endl;

	return 0;
}