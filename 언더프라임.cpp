#include <iostream>
#define MAX 100001

using namespace std;

bool prime[MAX];
int dp[MAX];

// 소인수 분해 알고리즘

int solve(int x)
{
	if (x == 1) return 0;
	if (dp[x] > 0) return dp[x];
	int ret = 0;
	if (x % 2 == 0) {
		ret = solve(x / 2)+1;
	}
	else {
		int i;
		for (i = 3; i <= x; ++i) {
			if (!prime[i] && x%i == 0) {
				break;
			}
		}
		ret = solve(x / i) + 1;
	}
	return dp[x] = ret;
}

int main(void)
{
	int A, B;
	cin >> A >> B;
	
	for (int i = 0; i <= B; ++i) {
		dp[i] = -1;
	}

	prime[1] = true;

	for (int i = 2; i*i <= MAX; ++i) {
		for (int j = 2; j*i <= MAX; ++j) {
			if (!prime[i*j]) {
				prime[i*j] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = A; i <= B; ++i) {
		if (!prime[solve(i)]) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}