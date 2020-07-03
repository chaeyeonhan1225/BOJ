#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<int> package;	// 패키지
	vector<int> piece;		// 낱개

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		package.push_back(a);
		piece.push_back(b);
	}

	// 오름차순으로 정렬
	sort(package.begin(), package.end());
	sort(piece.begin(), piece.end());

	int a = package[0];
	int b = piece[0];

	int ans = 9999999;

	if (a >= 6 * b) {
		ans = min(ans,b * N);
	}
	else {
		int k = N / 6;
		if (N % 6 != 0) k++;
		if (k * a < b * N) {
			ans =  min(ans,a * k);
		}
		
		int temp = 0;
		while (N > 6) {
			N -= 6;
			temp += a;
		}
		temp += b * N;
		ans = min(ans, temp);
	}

	cout << ans << "\n";

	return 0;
}