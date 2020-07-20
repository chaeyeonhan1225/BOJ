#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 11

using namespace std;

int N;
int a[MAX];
int b[MAX];

long long getFlavor(int pos, long long sour, long long bit,int cnt)
{
	if (pos == N) {
		if (cnt == 0) return 9999999999;	// 적어도 하나 이상의 재료를 사용해야한다.
		return abs(sour - bit);
	}

	return min(getFlavor(pos + 1, sour * a[pos + 1], bit + b[pos + 1],cnt+1), getFlavor(pos + 1, sour, bit,cnt));
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> a[i] >> b[i];
	}
	cout << getFlavor(0, 1, 0, 0) << "\n";

	return 0;
}