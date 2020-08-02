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
		if (t < a) {	// 수열의 마지막 부분보다 크다면
			s.push_back(a);
		}
		else {	// 아니라면 lower_bound로 들어갈 위치를 찾아 바꾼다.
			vector<int>::iterator it = lower_bound(s.begin(), s.end(),a);
			*it = a;
		}
	}
	// LIS의 길이 출력
	cout << s.size() << "\n";
	
	return 0;
}