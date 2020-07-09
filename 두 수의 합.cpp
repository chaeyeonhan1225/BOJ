#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		a.push_back(k);
	}
	int x;
	cin >> x;

	sort(a.begin(), a.end());
	
	int ans = 0;
	int end = n-1;
	for (int start = 0; start < end && end < n; ++start) {
		while (a[start] + a[end] > x && end > start) {
			end--;
		}
		if (start < end && a[start] + a[end] == x) {
			ans++; 
			end--;
		}
	}
	cout << ans << "\n";
	return 0;
}