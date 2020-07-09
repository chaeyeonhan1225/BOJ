#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<int> temp;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		temp.push_back(a);
	}

	int end = 0;  
	int sum = 0;
	int ans = -99999999;
	for (int start = 0; start <= N-K; ++start) {
		while (end-start < K && end < N) {
			sum += temp[end];
			end++;
		}
		ans = max(ans, sum);
		sum -= temp[start];
	}
	
	cout << ans << "\n";

	return 0;
}