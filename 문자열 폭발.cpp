#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	string  b;
	cin >> str;
	cin >> b;
	
	int cnt = 0;

	const int blen = b.length();
	
	string k;
	
	// 스택 이용
	for (int i = 0; i < (int)str.length(); ++i) {
		k += str[i];
		if (k.back() == b[blen - 1]) {
			int j = 0;
			for (; j < blen && i >= j; ++j) {
				if (k[k.length()-1-j] != b[blen - j - 1]) {
					break;
				}
			}
			if (j == blen) {
				for (int h = 0; h < blen; ++h) {
					k.pop_back();
				}
			}
			else {
				continue;
			}

		}
	}
	if (!k.empty()) {
		cout << k << endl;
	}
	else {
		cout << "FRULA" << endl;
	}

	return 0;
}