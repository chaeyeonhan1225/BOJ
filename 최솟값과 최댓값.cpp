#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];
int max_tree[4 * MAX];	// ÃÖ´ñ°ª Æ®¸®
int min_tree[4 * MAX];	// ÃÖ¼Ú°ª Æ®¸®

int max_init(int start, int end, int node)
{
	if (start == end) return max_tree[node] = arr[start];
	int mid = (start + end) / 2;
	int a = max_init(start, mid, node * 2);
	int b = max_init(mid + 1, end, node * 2 + 1);
	return max_tree[node] = max(a,b);
}

int min_init(int start, int end, int node)
{
	if (start == end) return min_tree[node] = arr[start];
	int mid = (start + end) / 2;
	int a = min_init(start, mid, node * 2);
	int b = min_init(mid + 1, end, node * 2 + 1);
	return min_tree[node] = min(a,b);
}

int getMax(int start, int end, int left, int right, int node)
{
	if (left > end || right < start) return -1;
	if (start >= left && right >= end) return max_tree[node];
	int mid = (start + end) / 2;
	int a = getMax(start, mid, left, right, node * 2);
	int b = getMax(mid + 1, end, left, right, node * 2 + 1);
	return max(a,b);
}

int getMin(int start, int end, int left, int right, int node)
{	
	if (left > end || right < start) return 1999999999;
	if (start >= left && right >= end) return min_tree[node];
	int mid = (start + end) / 2;
	int a = getMin(start, mid, left, right, node * 2);
	int b = getMin(mid + 1, end, left, right, node * 2 + 1);
	return min(a,b);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N-1; ++i) {
		cin >> arr[i];
	}
	fill(min_tree, min_tree + 4 * N + 1, 0);
	fill(min_tree, min_tree + 4 * N + 1, 1999999999);
	max_init(0, N-1, 1);
	min_init(0, N - 1, 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << getMin(0, N - 1, a - 1, b - 1, 1) << " " << getMax(0, N - 1, a - 1, b - 1, 1) << "\n";
	}
	return 0;
}