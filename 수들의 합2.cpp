#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<int> a;
	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;
		a.push_back(k);
	}

	int end = 0;
	int sum = 0;
	int cnt = 0;
	for (int start = 0; start < N; ++start) {
		while (sum < M && end < N) {
			sum += a[end];
			end++;
		}
		if (sum == M) cnt++;
		sum -= a[start];
	}

	cout << cnt << "\n";

	return 0;
}