#include <iostream>
#include <vector>
#define MAX 9

using namespace std;

int map[MAX][MAX];
int init[MAX][MAX];
int N, M;
int safeArea = 99;

vector<pair<int, int>> cctv;

void left(int y, int x) {
	while (x >= 0 && map[y][x] != 6) {
		if (map[y][x] == 0) {
			map[y][x--] = 7;
		}
		else {
			x--;
		}
	}
}

void right(int y, int x) {
	while (x <= M - 1 && map[y][x] != 6) {
		if (map[y][x] == 0) {
			map[y][x++] = 7;
		}
		else {
			x++;
		}

	}
}

void up(int y, int x) {
	while (y >= 0 && map[y][x] != 6) {
		if (map[y][x] == 0) {
			map[y--][x] = 7;
		}
		else {
			y--;
		}
	}
}

void down(int y, int x) {
	while (y <= N - 1 && map[y][x] != 6) {
		if (map[y][x] == 0) {
			map[y++][x] = 7;
		}
		else {
			y++;
		}
	}
}

void cctv1(int y,int x,int cur) {
	if (cur == 1) up(y,x);	// 북
	else if (cur == 2) right(y, x);	// 동
	else if (cur == 3) down(y, x);	// 남
	else left(y, x);	// 서
}

void cctv2(int y, int x, int cur) {
	if (cur == 1) {
		up(y, x);
		down(y, x);
	}
	else {
		left(y, x);
		right(y, x);
	}
}

void cctv3(int y, int x,int cur) {
	if (cur == 1) {
		up(y, x);
		right(y, x);
	}
	else if (cur == 2) {
		right(y, x);
		down(y, x);
	}
	else if (cur == 3) {
		down(y, x);
		left(y, x);
	}
	else {
		left(y, x);
		up(y, x);
	}
}

void cctv4(int y, int x, int cur) {
	if (cur == 1) {
		left(y, x);
		up(y, x);
		right(y, x);
	}
	else if (cur == 2) {
		up(y, x);
		right(y, x);
		down(y, x);
	}
	else if (cur == 3) {
		right(y, x);
		down(y, x);
		left(y, x);
	}
	else {
		down(y, x);
		left(y, x);
		up(y, x);
	}
}

void cctv5(int y, int x, int cur) {
	up(y, x);
	right(y, x);
	down(y, x);
	left(y, x);
}

// dfs로 수열 생성
void dfs(vector<int> &d, int cur,int k) {
	d.push_back(k);
	if (d.size() == cctv.size() || cur == cctv.size() - 1) {
		for (int i = 0; i < (int)d.size(); ++i) {
			int y = cctv[i].first;
			int x = cctv[i].second;
			if (map[y][x] == 1) {
				cctv1(y, x, d[i]);
			}
			else if (map[y][x] == 2) {
				cctv2(y, x, d[i]);
			}
			else if (map[y][x] == 3) {
				cctv3(y, x, d[i]);
			}
			else if (map[y][x] == 4) {
				cctv4(y, x, d[i]);
			}
			else {	
				cctv5(y, x, d[i]);
			}
			
			
 		}
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j] == 0) cnt++;
				map[i][j] = init[i][j];
			}
		}
		if (safeArea > cnt) {
			safeArea = cnt;
		}
		return;
	}
	int ny = cctv[cur + 1].first;
	int nx = cctv[cur + 1].second;
	if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4) {
		for (int i = 1; i <= 4; ++i) {
			dfs(d, cur + 1, i);
			d.pop_back();
		}
	}
	else if (map[ny][nx] == 2) {
		for (int i = 1; i <= 2; ++i) {
			dfs(d, cur + 1, i);    
			d.pop_back();
		}
	}
	else if (map[ny][nx] == 5) {
		dfs(d, cur + 1, 1);
		d.pop_back();
	}
}

int main(void) {
	
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			init[i][j] = map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}

	if (!cctv.empty()) {
		int y = cctv[0].first;
		int x = cctv[0].second;
		vector<int> d;
		if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4) {
			for (int i = 1; i <= 4; ++i) {
				dfs(d, 0, i);
				d.pop_back();
			}
		}
		else if (map[y][x] == 2) {
			for (int i = 1; i <= 2; ++i) {
				dfs(d, 0, i);
				d.pop_back();
			}
		}
		else if (map[y][x] == 5) {
			dfs(d, 0, 1);
			d.pop_back();
		}
	}
	else {
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j] == 0) {
					cnt++;
				}
			}
		}
		safeArea = cnt;
	}
	cout << safeArea << "\n";

	return 0;
}