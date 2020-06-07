#include <iostream>
#include <vector>
#define MAX 21

using namespace std;

int n;
int map[MAX][MAX];
int ans = 999999999;

int calc(vector<int> &s)
{
	int size = s.size();
	int score = 0;
	for (int i = 0; i <= size-1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			int a = s[i]-1;
			int b = s[j]-1;
			score = score + map[a][b] + map[b][a];
		}
	}
	return score;
}

void dfs(vector<int> &s,int crnt)
{
	s.push_back(crnt);
	if (s.size() == n / 2) {
		vector<int> l;
		for (int i = 1; i <= n; ++i) {
			int j;
			for (j = 0; j < n / 2 && s[j] != i; ++j)
				;
			if (j == n / 2) l.push_back(i);
		}
		int ret = abs(calc(s) - calc(l));
		if (ans > ret) ans = ret;
		return;
	}
	else {
		for (int i = 1; i + crnt <= n; ++i) {
			dfs(s, crnt + i);
			s.pop_back();
		}
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

	for (int i = 1; i <= n / 2; ++i) {
		vector<int> s;
		dfs(s, i);
	}
	cout << ans << endl;
	
	return 0;
}