#include <iostream>
#include <string>
#define MAX 101

using namespace std;

int N, M, K;
char board[MAX][MAX];	// 문자판
int dp[MAX][MAX][81];	// dp[y][x][단어의 길이]

// dfs & dp
int dfs(string& str, string& word, int y, int x) {
	str.push_back(board[y][x]);
	int k = str.size();
	if (str == word) {
		return dp[y][x][k] = 1;
	}
	if (dp[y][x][k] != -1) return dp[y][x][k];	// 이미 계산되어 있다면 계산된 값을 리턴한다.
	int ret = 0;
	char next = word[k];
	// 위, 아래, 왼쪽, 오른쪽으로 K 칸만큼만 이동 가능
	for (int i = 1; i <= K; ++i) {
		int ny = y + i;
		if (x >=0 && x < M && ny < N && board[ny][x] == next) {
			ret += dfs(str, word, ny, x);
			str.pop_back();
		}
		int yy = y - i;
		if (x >= 0 && x < M && yy >= 0 && board[yy][x] == next) {
			ret += dfs(str, word, yy, x);
			str.pop_back();
		}
		int nx = x + i;
		if (y >=0 && y < N && nx < M && board[y][nx] == next) {
			ret += dfs(str, word, y, nx);
			str.pop_back();
		}
		int xx = x - i;
		if (y >= 0 && y < N && xx >= 0 && board[y][xx] == next) {
			ret += dfs(str, word, y, xx);
			str.pop_back();
		}
	}
	return dp[y][x][k] = ret;	// 메모이제이션
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			// dp 배열 초기화
			fill(dp[i][j], dp[i][j] + 80, -1);
		}
	}
	cin >> word;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == word[0]) {	// 단어의 처음 문자와 일치하면
				string str;
				ans += dfs(str, word, i, j);
				str = "";	
			}
		}
	}
	cout << ans << "\n";
	return 0;
}