#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int> max_heap;	// ÃÖ´ë Èü
	priority_queue<int> min_heap;	// ÃÖ¼Ò Èü
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (i == 0) {
			max_heap.push(a);
		}
		else {
			int t = max_heap.top();
			if (a < t) {
				max_heap.push(a);
			}
			else {
				min_heap.push(-1 * a);
			}
			int k = 0;
			if (i % 2 == 0) k++;
			if (max_heap.size() == min_heap.size() + k) {
				cout << max_heap.top() << "\n";
				continue;
			}
			if (max_heap.size() > min_heap.size()+k) {
				int t = max_heap.top();
				max_heap.pop();
				min_heap.push(-1 * t);
			}
			else {
				int t = -1 * min_heap.top();
				min_heap.pop();
				max_heap.push(t);
			}
		}
		cout << max_heap.top() << "\n";
	}	
		

	return 0;
}