#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S;
	cin >> N >> S;
	vector<int> s;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		s.push_back(a);
	}

	int end = 0;
	long long sum = 0;
	int ans = 999999;
	for (int start = 0; start < N; ++start) {
		while (sum < S && end < N) {
			sum += s[end];
			end++;
		}
		if (sum < S && end == N) break;
		ans = min(ans, end - start);
		sum -= s[start];
	}
	if (ans < 999999)
		cout << ans << "\n";
	else
		cout << 0 << "\n";
	return 0;
}