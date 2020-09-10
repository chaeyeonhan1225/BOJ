#include <iostream>
#include <queue>
#define MAX 301

using namespace std;

int dir[8][2] = {
	{2,1},
	{1,2},
	{2,-1},
	{1,-2},
	{-1,2},
	{-2,1},
	{-1,-2},
	{-2,-1}
};
bool visited[MAX][MAX];

void init(int I) {
	for (int i = 0; i < I; ++i) {
		for (int j = 0; j < I; ++j) {
			visited[i][j] = false;
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int I;
		cin >> I;
		init(I);
		int sy, sx;	// Ãâ¹ß
		int dy, dx;	// µµÂø
		cin >> sy >> sx;
		cin >> dy >> dx;
		if (sy == dy && sx == dx) {
			cout << 0 << "\n";
			continue;
		}
		queue<pair<pair<int, int>, int>> q;
		visited[sy][sx] = true;
		q.push(make_pair(make_pair(sy, sx), 0));
		bool flag = true;
		while (!q.empty() && flag) {
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			for (int i = 0; i < 8; ++i) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				if (ny >= 0 && ny < I && nx >= 0 && nx < I && !visited[ny][nx]) {
					if (ny == dy && nx == dx) {
						cout << cnt + 1 << "\n";
						flag = false;
						break;
					}
					visited[ny][nx] = true;
					q.push(make_pair(make_pair(ny, nx), cnt + 1));
				}
			}
		}
	}

	return 0;
}