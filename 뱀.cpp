#include <iostream>
#include <vector>
#include <deque>

#define MAX 101

using namespace std;

bool map[MAX][MAX];
bool visited[MAX][MAX];         

//            동 서 남 북
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int getNextCur(int cur, char C) {
	int nextCur = 0;
	if (C == 'L') {
		if (cur == 0) nextCur = 3;
		if (cur == 1) nextCur = 2;
		if (cur == 2) nextCur = 0;
		if (cur == 3) nextCur = 1;
	}
	else {
		if (cur == 0) nextCur = 2;
		if (cur == 1) nextCur = 3;
		if (cur == 2) nextCur = 1;
		if (cur == 3) nextCur = 0;
	}
	return nextCur;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int K;
	cin >> N >> K;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < K; ++i) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	int L;
	cin >> L;
	int y = 1;
	int x = 1;
	int cur = 0; // 0: 동, 1: 서, 2: 남, 3: 북
	deque<pair<int, int>> snake;
	visited[1][1] = true;
	snake.push_front(make_pair(1, 1));

	bool gameover = false;
	int s = 0;
	for (int i = 0; i < L; ++i) {
		int X;
		char C;
		cin >> X >> C;
		while (s < X && !gameover) {
			int ny = y + dy[cur];
			int nx = x + dx[cur];
			
			if (ny > 0 && ny <= N && nx > 0 && nx <= N && !visited[ny][nx]) {
				snake.push_front(make_pair(ny, nx));
				visited[ny][nx] = true;
				if (!map[ny][nx] == 1) {	// 사과가 없으면
					pair<int, int> t = snake.back();
					visited[t.first][t.second] = false;
					snake.pop_back();
				}
				else {
					map[ny][nx] = 0;
				}
				y = ny;
				x = nx;
			}
			else {
				gameover = true;
			}
			s++;
		}
		cur = getNextCur(cur, C);
	}

	// 계속 진행할 수 있으면
	while (!gameover) {
		int ny = y + dy[cur];
		int nx = x + dx[cur];
		if (ny > 0 && ny <= N && nx > 0 && nx <= N && !visited[ny][nx]) {
			snake.push_front(make_pair(ny, nx));
			visited[ny][nx] = true;
			if (!map[ny][nx] == 1) {	// 사과가 없으면
				pair<int, int> t = snake.back();
				visited[t.first][t.second] = false;
				snake.pop_back();
			}
			else {
				map[ny][nx] = 0;
			}
			y = ny;
			x = nx;
		}
		else {
			gameover = true;
		}
		s++;
	}
	
	cout << s << "\n";
	
	return 0;
}