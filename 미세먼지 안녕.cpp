#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int N, M, T;
int map[MAX][MAX];
int temp[MAX][MAX];
queue<pair<int, int>> dust;	// 미세먼지
vector<pair<int, int>> p;	// 공기청정기

void purifyUp() {	// 반시계 방향으로 순환
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			temp[i][j] = map[i][j];
		}
	}
	int y = p[0].first;
	int x = p[0].second + 1;
	while (x + 1 < M) {
		map[y][x + 1] = temp[y][x];
		x++;
	}
	while (y - 1 >= 0) {
		map[y - 1][x] = temp[y][x];
		y--;
	}
	while (x - 1 >= 0) {
		map[y][x - 1] = temp[y][x];
		x--;
	}
	while (y + 1 <= p[0].first) {
		map[y + 1][x] = temp[y][x];
		y++;
	}
	map[p[0].first][p[0].second] = -1;
	map[p[0].first][p[0].second + 1] = 0;
}

void purifyDown() {	// 시계방향으로 순환
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			temp[i][j] = map[i][j];
		}
	}
	int y = p[1].first;
	int x = p[1].second + 1;
	while (x + 1 < M) {
		map[y][x + 1] = temp[y][x];
		x++;
	}
	while (y + 1 < N) {
		map[y + 1][x] = temp[y][x];
		y++;
	}
	while (x - 1 >= 0) {
		map[y][x - 1] = temp[y][x];
		x--;
	}
	while (y - 1 >= p[1].first) {
		map[y - 1][x] = temp[y][x];
		y--;
	}
	
	map[p[1].first][p[1].second] = -1;
	map[p[1].first][p[1].second + 1] = 0;
}

void spread() {	// 미세먼지 확산
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			temp[i][j] = 0;
		}
	}
	while (!dust.empty()) {
		int y = dust.front().first;
		int x = dust.front().second;
		dust.pop();
		int cnt = 0;
		if (x + 1 < M && map[y][x + 1] != -1) {
			temp[y][x + 1] += (map[y][x] / 5);
			cnt++;
		}
		if (x - 1 >= 0 && map[y][x - 1] != -1) {
			temp[y][x - 1] += (map[y][x] / 5);
			cnt++;
		}
		if (y + 1 < N && map[y + 1][x] != -1) {
			temp[y + 1][x] += (map[y][x] / 5);
			cnt++;
		}
		if (y - 1 >= 0 && map[y - 1][x] != -1) {
			temp[y - 1][x] += (map[y][x] / 5);
			cnt++;
		}
		temp[y][x] += map[y][x] - (map[y][x] / 5) * cnt;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == -1) temp[i][j] = -1;
			map[i][j] = temp[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				p.push_back(make_pair(i, j));
			}
		}
	}
	
	while (T--) {
		// 미세먼지들을 큐에 넣어준다.
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j] > 0) {
					dust.push(make_pair(i, j));
				}
			}
		}
		// 1초가 지나갈때마다 수행
		spread();
		purifyUp();
		purifyDown();
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] != -1) ans += map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}