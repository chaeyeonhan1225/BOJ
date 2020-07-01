#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int M;
		cin >> M;
		vector<int> ans;
		priority_queue<int> max_heap;	// ÃÖ´ë Èü
		priority_queue<int> min_heap;	// ÃÖ¼Ò Èü
		for (int i = 1; i <= M; ++i) {
			int a;
			cin >> a;
			if (i == 1) {
				max_heap.push(a);
			}
			else {
				int t = max_heap.top();
				if (t <= a) {
					min_heap.push(-1 * a);
				}
				else {
					max_heap.push(a);
				}
		
				int k = 0;
				if (i % 2 == 1) k++;
				if (max_heap.size() < min_heap.size()) {
					int t = -1 * min_heap.top();
					min_heap.pop();
					max_heap.push(t);
				}
				if (max_heap.size() > min_heap.size() + k) {
					int t = max_heap.top();
					max_heap.pop();
					min_heap.push(-1 * t);
				} 
			}
			if (i % 2 == 1) {
				int t = max_heap.top();
				ans.push_back(t);
			}
		}
		cout << ans.size() << "\n";
		for (int i = 1; i <= (int)ans.size(); ++i) {
			cout << ans[i-1] << " ";
			if (i % 10 == 0) cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}