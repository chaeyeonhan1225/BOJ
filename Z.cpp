#include <iostream>
#include <cmath>

using namespace std;

int r, c;
bool flag = false;

int solve(int y, int x, int size)
{
	if (!flag) {
		if (size==2&&y <= r && y + size-1 >= r&&x <= c && x + size-1 >= c) {
			// 범위 안이면
			int cnt = 0;
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					if (y + i == r && x + j == c) {
						flag = true;
						return cnt;
					}
					cnt++;
				}
			}
		}
		else if(size==2){
			return 4;
		}
		else {
			int half = size / 2;
			return solve(y, x, half) + solve(y, x + half, half) +
				solve(y + half, x, half) + solve(y + half, x + half, half);

		}
	}
	else {
		return 0;
	}
}

int main(void)
{
	int n;
	cin >> n;
	cin >> r >> c;
	int size = (int)pow(2, n);

	cout << solve(0, 0, size) << endl;

	return 0;
}