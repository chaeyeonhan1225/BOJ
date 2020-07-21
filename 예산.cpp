#include <iostream>
#define MAX 10001

using namespace std;

int b[MAX];

// 계산과정에서 오버플로우가 발생할 수 있다.
long long getBudget(int N, int mid)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		if (mid > b[i]) {
			sum += b[i];
		}
		else {
			sum += (long long)mid;
		}
	}
	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int left = 0;
	int right = 0;

	for (int i = 0; i < N; ++i) {
		cin >> b[i];
		if (right < b[i]) right = b[i];
	}
	int M;
	cin >> M;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int budget = getBudget(N, mid);
		if (budget > M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << right << "\n";
	
	return 0;
}