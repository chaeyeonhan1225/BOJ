#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

void solve(int x)
{
	if (x == 0) {
		if (!pq.empty()) {
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			cout << 0 << '\n';
		}
	}
	else {
		pq.push(x);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		solve(x);
	}

	return 0;
}