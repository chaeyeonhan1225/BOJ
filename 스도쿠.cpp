#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> v;
bool flag = false;

// 유망한지 판단
bool isPossible(int y, int x, int next) {
	for (int i = 0; i < 9; ++i) {
		if (board[y][i] == next) {
			return false;
		} 
		if (board[i][x] == next) {
			return false;
		}
	}
	int y1 = 0, x1 = 0;
	int y2 = 0, x2 = 0;
	if (y < 3) {
		if (x < 3) {
			y1 = 0;
			x1 = 0;
			y2 = 2;
			x2 = 2;
		}
		else if (x < 6) {
			y1 = 0;
			x1 = 3;
			y2 = 2;
			x2 = 5;
		}
		else if (x < 9) {
			y1 = 0;
			x1 = 6;
			y2 = 2;
			x2 = 8;
		}
	}
	else if (y < 6) {
		if (x < 3) {
			y1 = 3;
			x1 = 0;
			y2 = 5;
			x2 = 2;
		}
		else if (x < 6) {
			y1 = 3;
			x1 = 3;
			y2 = 5;
			x2 = 5;
		}
		else if (x < 9) {
			y1 = 3;
			x1 = 6;
			y2 = 5;
			x2 = 8;
		}
	}
	else if (y < 9) {
		if (x < 3) {
			y1 = 6;
			x1 = 0;
			y2 = 8;
			x2 = 2;
		}
		else if (x < 6) {
			y1 = 6;
			x1 = 3;
			y2 = 8;
			x2 = 5;
		}
		else if (x < 9) {
			y1 = 6;
			x1 = 6;
			y2 = 8;
			x2 = 8;
		}
	}
	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			if (board[i][j] == next) {
				return false;
			}
		}
	}
	return true;
}

void back_tracking(int y, int x, int k, int cur) {
	board[y][x] = cur;
	if (k == v.size() - 1) {
		flag = true;	// 한번만 출력해주기 위해서 
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}

		return;
	}
	int ny = v[k + 1].first;
	int nx = v[k + 1].second;
	for (int i = 1; i <= 9; ++i) {
		if (isPossible(ny, nx, i)) {
			board[ny][nx] = i;
			if (!flag) {
				back_tracking(ny, nx, k + 1, i);
			}
			board[ny][nx] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= 9; ++i) {
		if (isPossible(v[0].first, v[0].second, i)) {
			back_tracking(v[0].first, v[0].second, 0, i);
		}
	}

	
	
	return 0;
}