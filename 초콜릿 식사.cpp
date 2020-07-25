#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int K;
	cin >> K;
	int minSize = 0;
	int chocolate = 0;
	
	for (int i = 0; i < 21; ++i) {
		int a = pow(2, i);
		if (K <= a) {
			minSize = a;
			chocolate = a;
			break;
		}
	}
	int ans = 0;
	while (1) {
		if (K <= 0) break;	// 정사각형 K개 초콜릿 다 먹을 수 있으면 break
		if (chocolate <= K) {
			K -= chocolate;
		}
		else {
			chocolate /= 2;	// 초콜릿을 반으로 나눈다.
			ans++;
		}
	}
	cout << minSize << " " << ans << "\n";
	
	return 0;
}