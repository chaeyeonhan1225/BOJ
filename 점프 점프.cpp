#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int a[MAX];
int dp[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		dp[i] = 9999999;
	}
	
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= a[i]; ++j) {
			if (dp [i + j] == 9999999) {
				dp[i + j] = dp[i] + 1;
			}
			else {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
	}
	// 이동할 수 없으므로 0이 답이다.
	if (N == 1) {
		cout << 0 << "\n";
	}
	else {
		if (a[0]!=0 && dp[N - 1] > 0 && dp[N-1] < 9999999)
			cout << dp[N - 1] << "\n";
		else
			cout << -1 << "\n";	// 이동할 수 없는 경우
	}

	return 0;
}