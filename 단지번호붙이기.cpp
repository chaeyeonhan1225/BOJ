#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[26][26];
bool visit[26][26];
int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { 1,-1,0,0 };
int result = 0;
vector<int> ans;

void DFS(int x, int y,int size)
{
	visit[x][y] = true;
	result++;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dy[i];
		int ny = y + dx[i];
		if (nx > 0 && nx <= size && ny > 0 && ny <= size && visit[nx][ny] == false &&
			map[nx][ny] == 1) {
			DFS(nx, ny,size);
		}
	}

}
int main(void)
{
	int n;	//아파트 단지의 크기
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf_s("%1d", &map[i][j]);
	}
	
	int a = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] != 0 && visit[i][j] != true) {
				DFS(i, j, n);
				a++;
				ans.push_back(result);
				result = 0;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << a << '\n';
	for (auto& element : ans)
		cout << element << '\n';

	return 0;
}