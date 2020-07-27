#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int N;
int a[MAX];
int op[4];
int d[4];
char b[4] = { '+','-','x','/' };
int max_ans = -2000000001;
int min_ans = 2000000001;

// 연산자 포함 수식 계산
int calc(vector<char>& s)
{
	vector<int> stk;	// 스택 활용해서 계산
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			stk.push_back(a[i]);
			continue;
		} 
		int top = stk.back();
		stk.pop_back();
		if (s[i - 1] == '+') {
			stk.push_back(top + a[i]);
		}
		if (s[i - 1] == '-') {
			stk.push_back(top - a[i]);
		}
		if (s[i - 1] == 'x') {
			stk.push_back(top * a[i]);
		}
		if (s[i - 1] == '/') {
			if (top < 0) {
				top *= -1;
				stk.push_back(-1 * (top / a[i]));
			}
			else {
				stk.push_back(top / a[i]);
			}
		}
	}
	int ret = stk.back();
	return ret;
}

void back_tracking(vector<char>& s, int k)
{
	s.push_back(b[k]);
	op[k]--;
	if (s.size() == N - 1) {
		int ret = calc(s);
		if (ret > max_ans) max_ans = ret;
		if (ret < min_ans) min_ans = ret;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			back_tracking(s, i);
			s.pop_back();
			op[i]++;
		}
	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
		d[i] = op[i];
	}

	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			vector<char> s;
			back_tracking(s, i);
			// op 초기화
			for (int i = 0; i < 4; ++i) {
				op[i] = d[i];
			}
		}
	}
	cout << max_ans << "\n";
	cout << min_ans << "\n";
	return 0;
}