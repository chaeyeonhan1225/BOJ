#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500005

using namespace std;

int v[MAX];
int p[MAX];
bool possible[MAX];

// LIS 가능한 인덱스 구하기
void getPosition(int idx, int num)
{
	if (idx == 0 || num == 0) return;
	if (num == p[idx]) {
		possible[idx] = true;
		getPosition(idx - 1, num - 1);
	}
	else {
		getPosition(idx - 1, num);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	
	int max = 0;
	
	// 배열 초기화
	fill(v, v + MAX, 0);

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
		// max 구하기
		if (max < b) {
			max = b;
		}
		if (max < a) {
			max = a;
		}
	}

	vector<int> d;
	int len = 0;
	for (int i = 1; i <= max; ++i) {
		if (v[i] > 0) {
			if (d.empty()) {
				d.push_back(v[i]);
				p[i] = ++len;
				continue;
			} 
			if (d.back() < v[i]) {
				d.push_back(v[i]);
				p[i] = ++len;
			}
			else {
				vector<int>::iterator it = lower_bound(d.begin(), d.end(), v[i]);
				*it = v[i];
				p[i] = it - d.begin() + 1;
			}
		}
	}
	cout << N-len << "\n";
	getPosition(max, len);
	for (int i = 1; i <= max; ++i) {
		if (!possible[i] && v[i] > 0) {
			cout << i << "\n";
		}
	}
	
	return 0;
}