#include <iostream>
#include <string>

using namespace std;

int N;
int cnt = 0;

void brute_force(string& str, int cur) {
	str += cur + '0';
	if (str.length() == N) {
		// 3의 배수가 되는지 검사
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += str[i] - '0';
		}
		if (sum % 3 == 0) {
			cnt++;
		}
		return;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			brute_force(str, i);
			str.pop_back();
		}
	}
}
int main(void) {	
	cin >> N;
	for (int i = 1; i < 3; ++i) {
		string str = "";
		brute_force(str, i);
	}

	cout << cnt << "\n";
	return 0;
}