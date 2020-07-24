#include <iostream>
#include <string>
#define MAX 31
using namespace std;

long long dp[MAX][MAX];
 
long long dfs(int half, int pill)
{
	if (dp[half][pill] > 0) return dp[half][pill];
	if (pill == 0) return 1;
	long long ret = 0;
	if(half	> 0)
		ret += dfs(half-1, pill);
	ret += dfs(half + 1, pill - 1);
	dp[half][pill] = ret;
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < MAX; ++i) {
		fill(dp[i], dp[i] + MAX + 1, -1);
	}
	while (1) {
		int N;
		cin >> N;
		if (N == 0) break;
		cout << dfs(0, N) << "\n";
	}
	
	return 0;
}