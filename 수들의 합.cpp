#include <iostream>
#define MAX 1000001
using namespace std;

long long s[MAX];
long long tree[MAX*4];

// 트리 초기화
long long init(int start, int end, int node) {
	if (start == end) return tree[node] = s[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// 구간 합 구하기
long long sum(int start, int end, int left, int right, int node) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

// 특정 노드 데이터 수정
void update(int start, int end, int node, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, diff);
		update(mid + 1, end, node * 2 + 1, index, diff);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; ++i) {
		s[i] = 0;
	}
	init(1, N, 1);
	for (int i = 0; i < M; ++i) {
		int f, a;
		long long b;
		cin >> f >> a >> b;	// a < b 일 수도 있고, a > b 일 수도 있음
		if (f == 0) {
			// sum
			if (a < b) {	// a < b인 경우
				cout << sum(1, N, a, (int)b, 1) << "\n";
			}
			else {	// b > a인 경우
				cout << sum(1, N, (int)b, a, 1) << "\n";
			}
		}
		else {
			// modify
			update(1, N, 1, a, b - s[a]);
			s[a] = b;
			
		}
	}
	return 0;
}