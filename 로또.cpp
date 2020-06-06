#include <iostream>
#include <vector>

using namespace std;

bool visited[49];

void print(vector<int>& b)
{
	for (int i = 0; i < 6; ++i)
		cout << b[i] << " ";
	cout << endl;
}

void initialize(int n)
{
	for (int i = 0; i < n; ++i)
		visited[i] = false;
}

void lotto(int num,int n, vector<int> &a,vector<int> &b)
{
	b.push_back(a[num]);
	if (a.size() < 6)
		return;			//a의 사이즈가 6보다 작으면 안됨
	if (b.size() == 6) {
		print(b);
		return;
	}
	else {
		for (int i = 1; i < n-1; ++i) {
			int next = num + i;
			if (!visited[next]&&next<n) {
				visited[next] = true;
				lotto(next, n, a, b);
				visited[next] = false;
				b.pop_back();
			}
			else
				continue;
		}
		return;
	}
}

int main(void)
{
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			a.push_back(num);
		}
		
		for (int i = 0; i <= n - 6; ++i) {
			vector<int> b;
			lotto(i, n, a, b);
			initialize(n);
		}
		cout << endl;
	}
	
	return 0;
}