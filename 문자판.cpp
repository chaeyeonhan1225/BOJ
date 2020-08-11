#include <iostream>
#include <string>
#define MAX 101

using namespace std;

int N, M, K;
char board[MAX][MAX];	// ������
int dp[MAX][MAX][81];	// dp[y][x][�ܾ��� ����]

// dfs & dp
int dfs(string& str, string& word, int y, int x) {
	str.push_back(board[y][x]);
	int k = str.size();
	if (str == word) {
		return dp[y][x][k] = 1;
	}
	if (dp[y][x][k] != -1) return dp[y][x][k];	// �̹� ���Ǿ� �ִٸ� ���� ���� �����Ѵ�.
	int ret = 0;
	char next = word[k];
	// ��, �Ʒ�, ����, ���������� K ĭ��ŭ�� �̵� ����
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
	return dp[y][x][k] = ret;	// �޸������̼�
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
			// dp �迭 �ʱ�ȭ
			fill(dp[i][j], dp[i][j] + 80, -1);
		}
	}
	cin >> word;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == word[0]) {	// �ܾ��� ó�� ���ڿ� ��ġ�ϸ�
				string str;
				ans += dfs(str, word, i, j);
				str = "";	
			}
		}
	}
	cout << ans << "\n";
	return 0;
}