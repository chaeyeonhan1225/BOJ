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
	cin >> N;
	vector<int> s;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (s.empty()) {
			s.push_back(a);
			continue;
		}
		int t = s.back();
		if (t < a) {	// ������ ������ �κк��� ũ�ٸ�
			s.push_back(a);
		}
		else {	// �ƴ϶�� lower_bound�� �� ��ġ�� ã�� �ٲ۴�.
			vector<int>::iterator it = lower_bound(s.begin(), s.end(),a);
			*it = a;
		}
	}
	// LIS�� ���� ���
	cout << s.size() << "\n";
	
	return 0;
}