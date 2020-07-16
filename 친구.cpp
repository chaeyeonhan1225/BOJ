#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 999999

using namespace std;

int a[MAX][MAX];

int floydWarshall(int N)
{
	int cnt = 0;
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (a[i][j] > 0 && a[i][j] <= 2) {	// 자기자신이 아니고 거리가 2이하이면
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}
int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = INF;
		}
		a[i][i] = 0;
	}

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j) { 
			if (str[j] == 'Y') {
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
	}

	cout << floydWarshall(N) << "\n";
	

	return 0;
}