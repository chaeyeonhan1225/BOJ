#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

// 은하의 수: n, 철도의 개수: m
int n, m;
int galaxy[MAX];
long long answer[MAX];

int getParent(int x)
{
	if (galaxy[x] == x) return x;
	return galaxy[x] = getParent(galaxy[x]);
}

long long unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b) {
		return answer[a];
	}
	else if (a < b) {
		galaxy[b] = a;
		answer[a] += answer[b];
		return answer[a];
	}
	else {
		galaxy[a] = b;
		answer[b] += answer[a];
		return answer[b];
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		long long planet;
		cin >> planet;
		answer[i] = planet;
		galaxy[i] = i;
	}
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << unionParent(a, b) << "\n";
	}

	return 0;
}