#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> c;
	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		c.push_back(w);
	}

	sort(c.begin(), c.end());

	int m;
	cin >> m;
	vector<int> box;
	for (int i = 0; i < m; ++i) {
		int w;
		cin >> w;
		box.push_back(w);
	}
	
	sort(box.begin(), box.end());

	int cnt = 0;

	if (c.back() < box.back()) {
		cout << -1 << endl;
	}
	else {
		while (1) {
			if (box.empty()) break;
			for (int i = n - 1; i >= 0; --i) {
				if (!box.empty()) {
					if (box.back() < c[i]) {
						box.pop_back();
					}
				}
				else {
					break;
				}
			}
			cnt++;
		}
	}
	cout << cnt << endl;
	
	return 0;
}