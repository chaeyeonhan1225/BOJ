#include <iostream>
#define MAX 1001
#define NUM 1000000007

using namespace std;

long long arr[MAX];
long long tree[4*MAX];

// 트리 초기화
long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = ((init(start, mid, node * 2) % NUM) * (init(mid + 1, end, node * 2 + 1) % NUM)) % NUM;
}

// 구간 곱 구하기
long long getMultiple(int start, int end, int left, int right, int node)
{
	if (left > end || right < start) return 1;
	if (start >= left && end <= right) return tree[node]%NUM;
	int mid = (start + end) / 2;
	return ((getMultiple(start, mid, left, right, node * 2) % NUM) * (getMultiple(mid + 1, end, left, right, node * 2 + 1) % NUM)) % NUM;
}

// 요소 수정 (divided by zero주의)
long long update(int start, int end, int index, int node, int diff)
{
	if (start > index || index > end) return tree[node] % NUM;
	if (start == end) return tree[node] = diff % NUM;

	int mid = (start + end) / 2;
	return tree[node] = ((update(start, mid, index, node * 2, diff) % NUM) * (update(mid + 1, end, index, node * 2 + 1, diff) % NUM)) % NUM;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, N - 1, b - 1, 1, c);
			arr[b - 1] = c;
		}
		else {
			cout << getMultiple(0, N - 1, b - 1, c - 1, 1) << "\n";
		}
	}

	return 0;
}