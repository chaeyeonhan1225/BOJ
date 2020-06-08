#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	int ans = 0;
	int acc = 0;
	for (int i = 0; i < N; ++i) {
		int d, r, g;
		cin >> d >> r >> g;
		ans += (d - acc);
		acc = d;
		vector<int> temp;
		while (r > 0) {
			temp.push_back(r--);
		}
		while (g > 0) {
			temp.push_back(0);
			g--;
		}
		int k = ans % temp.size();
		ans += temp[k];
	}
	ans += (L - acc);
	cout << ans << "\n";
	;
	return 0;
}