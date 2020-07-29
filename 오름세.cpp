#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	while (cin >> N) {	// �Է�
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			int price;
			cin >> price;
			a[i] = price;
		}
		vector<int> b;
		
		for (int i = 0; i < N; ++i) {
			if (b.empty()) {
				b.push_back(a[i]);
				continue;
			}
			int t = b.back();
			if (t < a[i]) {
				b.push_back(a[i]);
			}
			else {
				// t >= a[i] �϶� 
				vector<int>::iterator it = lower_bound(b.begin(), b.end(), a[i]);
				*it = a[i];
			}
		}
		// LIS ���� ���
		cout << b.size() << "\n";
	}
	return 0;
}