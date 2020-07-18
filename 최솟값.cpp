#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 1000000010

using namespace std;

int arr[MAX];
int tree[4 * MAX];

// 트리 초기화
int init(int start, int end, int node)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	int a = init(start, mid, node * 2);
	int b = init(mid + 1, end, node * 2 + 1);
	return tree[node] = min(a, b);
}

// 구간 최솟값 구하기
int getMin(int start, int end, int left, int right, int node)
{	
	if (left > end || right < start) return INF;
	if (start >= left && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int a = getMin(start, mid, left, right, node * 2);
	int b = getMin(mid + 1, end, left, right, node * 2 + 1);
	return min(a, b);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	fill(tree, tree + 4 * N + 1, INF);
	init(0, N - 1, 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << getMin(0, N - 1, a - 1, b - 1, 1) << "\n";
	}
	
	return 0;
}