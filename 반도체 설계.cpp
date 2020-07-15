#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// LIS
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> port;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		port.push_back(a);
	}

	vector<int> d;
	for (int i = 0; i < N; ++i) {
		if (d.empty()) {
			d.push_back(port[i]);
			continue;
		}
		if (d.back() < port[i]) {
			d.push_back(port[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(d.begin(), d.end(), port[i]);
			*it = port[i];
		}
	}

	cout << d.size() << "\n";
	return 0;
}