#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int max(int dp[],int k)
{
	int maximum = dp[1];
	for (int i = 2; i <= k; ++i) {
		if (maximum < dp[i])
			maximum = dp[i];
	}
	return maximum;
}

int max_all(int (*dp)[MAX],int k)
{
	int maximum = dp[1][1];
	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (maximum < dp[i][j])
				maximum = dp[i][j];
		}
	}
	return maximum;
}
int main(void)
{
	int n;
	vector<int> card;
	int dp[MAX][MAX];

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		card.push_back(num);
	}

	dp[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (card[j - 1] < card[i - 1])
				dp[i][j] = max(dp[j], j) + 1;
			else
				dp[i][j] = 0;
		}
		dp[i][i] = 1;
	}

	cout << max_all(dp,n) << endl;

	return 0;
}