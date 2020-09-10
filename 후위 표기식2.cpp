#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	string str;
	cin >> str;
	vector<double> num;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	
	// stack
	vector<double> stk;	

	for (int i = 0; i < (int)str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int k = str[i] - 'A';
			stk.push_back(num[k]);
		}
		else {
			double b = stk.back();
			stk.pop_back();
			double a = stk.back();
			stk.pop_back();
			if (str[i] == '+') {
				stk.push_back(a + b);
			}
			else if (str[i] == '-') {
				stk.push_back(a - b);
			}
			else if (str[i] == '*') {
				stk.push_back(a * b);
			}
			else {	// str[i] == '/'
				stk.push_back(a / b);
			}
		}
	}
	// 소수점 둘째자리 수까지 표시
	cout << fixed << setprecision(2) << stk[0] << "\n";
	
	return 0;
}