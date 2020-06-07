#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char map[6][6];
bool visited[6][6];
const int dy[4] = {1,0};	//╩С го аб ©Л
const int dx[4] = {0,1};
vector<int> result;

int calc(vector<char>& a){
	int ret = a[0]-'0';
	int flag = 0;
	for (int i = 1; i < (int)a.size(); ++i) {
		int k = 0;
		if (a[i] != '+'&&a[i] != '-'&&a[i] != '*') {
			k = a[i] - '0';
		}
		else {
			if (a[i] == '+')
				flag = 0;
			else if (a[i] == '-')
				flag = 1;
			else {
				flag = 2;
				k = 1;
			}
		}
		if (flag == 0)
			ret += k;
		else if (flag == 1)
			ret -= k;
		else
			ret *= k;

	}
	return ret;
}

void calcmax(int y, int x, int currentvalue,vector<char>& a)
{
	a.push_back(map[y][x]);
	if (y == n && x == n) {
		result.push_back(calc(a));
		return;
	}
	for (int i = 0; i < 2; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx] == false && ny >= 1 && ny <= n && nx >= 1 &&
			nx <= n) {
			visited[ny][nx] = true;
			calcmax(ny, nx, currentvalue,a);
			visited[ny][nx] = false;
			a.pop_back();
		}
		else
			continue;
	}
	return ;
}

int main(void)
{
	vector<char> a;

	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> map[i][j];
	}


	visited[1][1] = true;
	calcmax(1, 1, 0,a);
	sort(result.begin(), result.end());
	cout << result.back() << " " << result.front() << endl;
	
	return 0;
}