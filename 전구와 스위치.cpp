#include <iostream>
#include <cstdio>

using namespace std;

int bt[100001];
int temp[100001];
int result[100001];
int cnt = 0;

bool compare(int a[],int n)
{
	for (int i = 1; i <= n; ++i) {
		if (a[i] != result[i])
			return false;
	}
	return true;
}

void change(int a[],int sw,int n)
{
	for (int j = -1; j < 2; ++j) {
		if(sw+j>0&&sw+j<=n)
			a[sw + j] = 1 - a[sw + j];
	}
	cnt++;
}

int main(void)
{
	int n;
	cin >> n;


	for (int i = 1; i <= n; ++i) {
		scanf_s("%1d", &bt[i]);
		temp[i] = bt[i];
	}

	for (int i = 1; i <= n; ++i) {
		scanf_s("%1d", &result[i]);
	}

	//temp는 1눌렀을때
	//bt는 1안눌렀을때
	
	change(temp, 1, n);

	int tcnt = 1;
	int bcnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (temp[i - 1] != result[i - 1]) {
			change(temp, i, n);
			tcnt++;
		}
		if (bt[i - 1] != result[i - 1]) {
			change(bt, i, n);
			bcnt++;
		}
	}

	int ans = -1;
	int flag = 0;
	if (compare(temp, n))
		ans = tcnt;
	else if (compare(bt, n))
		ans = bcnt;

	if (compare(temp, n) == true && compare(bt, n)==true)
		ans = tcnt < bcnt ? tcnt : bcnt;


	cout << ans << endl;

	return 0;
}