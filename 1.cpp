#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	while (cin >> n) {
		int a = 1;
		int ans = 1;
		while(1) {
			if (a % n == 0) {
				cout << ans << "\n";
				break;
			}
			else {
				a = (a * 10) % n + 1;
				ans++;
			}
		}
	}

	return 0;
}