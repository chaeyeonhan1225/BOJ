#include <iostream>
#define MAX 1000010
using namespace std;

long long s[MAX];
long long tree[4 * MAX];

// 트리 초기화
long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = s[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// 구간 합 
long long sum(int start, int end, int left, int right, int node)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

// 요소 수정
void update(int start, int end, int node, int index, long long dif)
{
	if (index < start || index > end) return;
	tree[node] += dif;
	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, dif);
		update(mid + 1, end, node * 2 + 1, index, dif);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> s[i];
	}
	init(1, N, 1);
	for (int i = 0; i < M + K; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c - s[b]);
			// 기존 배열의 원소도 수정해줘야함
			s[b] = c;
		}
		else {
			cout << sum(1, N, b, (int)c, 1) << "\n";
		}
	}

	return 0;
}