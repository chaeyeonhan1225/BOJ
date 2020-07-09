#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<bool> notprime(N + 1, false);

	for (int i = 2; i * i < N; ++i) {
		if (!notprime[i]) {
			for (int j = 2; i * j <= N; ++j) {
				if (!notprime[i * j]) {
					notprime[i * j] = true;
				}
			}
		}
	}
	vector<int> prime;
	for (int i = 2; i <= N; ++i) {
		if (!notprime[i]) {
			prime.push_back(i);
		}
	}
	int s = prime.size();
	int end = 0;
	int sum = 0;
	int ans = 0;
	for (int start = 0; start < s; ++start) {
		while (sum < N && end < s) {
			sum += prime[end];
			end++;
		}
		if (sum == N) ans++;
		sum -= prime[start];
	}
	
	cout << ans << "\n";

	return 0;
}