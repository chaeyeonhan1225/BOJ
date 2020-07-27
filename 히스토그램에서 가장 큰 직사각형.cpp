#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> histogram;

long long solve(int left, int right) 
{
	// ���������϶�
	if (left == right) return histogram[left];
	long long mid = (left + right) / 2;
	// ����,������ ���簢���߿� ū �� ���
	long long ret = max(solve(left, mid), solve(mid+1,right));
	long long lo = mid;
	long long hi = mid + 1;
	long long height = min(histogram[lo], histogram[hi]);
	ret = max(ret, height * 2);

	// ����� �����ִ� ���簢�� ���� ���
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || histogram[lo - 1] < histogram[hi + 1])) {
			++hi;
			height = min(height, histogram[hi]);
		}
		else {
			--lo;
			height = min(height, histogram[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		int t;
		cin >> t;
		if (t == 0) break;
		for (int i = 0; i < t; ++i) {
			long long h;
			cin >> h;
			histogram.push_back(h);
		}
		cout << solve(0, t - 1) << "\n";
		histogram.clear();
	}
	return 0;
}