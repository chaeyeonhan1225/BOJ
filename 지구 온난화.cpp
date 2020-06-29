#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 11

using namespace std;

char map[MAX][MAX];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int r, c;

bool compare(pair<int,int> a,pair<int,int> b)
{
	if (a.second < b.second) {
		return true;
	}
	else
		return false;
}

int check(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (map[ny][nx] == '.' || ny < 0 || ny >= r || nx < 0 || nx >= c) {
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	cin >> r >> c;
	
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
		}
	}

	vector<pair<int, int>> sea;
	vector<pair<int, int>> land;
	
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (map[i][j] == 'X') {
				if (check(i, j) >= 3) {
					sea.push_back(make_pair(i, j));
				}
				else {
					land.push_back(make_pair(i, j));
				}
			}
		}
	}

	for (int i = 0; i < (int)sea.size(); ++i) {
		map[sea[i].first][sea[i].second] = '.';
	}

	sort(land.begin(), land.end());	// y 가 제일 작은 거
	int lefty = land[0].first;
	int righty = land[land.size()-1].first;

	sort(land.begin(), land.end(), compare);
	int leftx = land[0].second;
	int rightx = land[land.size()-1].second;

	for (int i = lefty; i <= righty; ++i) {
		for (int j = leftx; j <= rightx; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}