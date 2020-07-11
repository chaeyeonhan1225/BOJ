#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> a(N + 1);
	vector<int> prefix_sum(N+1,0);

	for (int i = 1; i <= N; ++i) {
		int k;
		cin >> k;
		a[i] = k;
		prefix_sum[i] = prefix_sum[i - 1] + a[i];
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int L, R;
		cin >> L >> R;
		cout << prefix_sum[R] - prefix_sum[L - 1] << "\n";
	}

	return 0;
}