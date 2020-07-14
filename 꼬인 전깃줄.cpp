#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// LIS ±¸ÇÏ±â
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> a(N+1);
	for (int i = 1; i <= N; ++i) {
		int k;
		cin >> k;
		a[i] = k;
	}
	vector<int> s;
	for (int i = 1; i <= N; ++i) {
		if (s.empty()) {
			s.push_back(a[i]);
			continue;
		}
		if (s.back() < a[i]) {
			s.push_back(a[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(s.begin(), s.end(), a[i]);
			*it = a[i];
		}
	}
	cout << N - s.size() << "\n";

	return 0;
}