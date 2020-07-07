#include <iostream>
#include <string>

using namespace std;

char num[5][3][4];
char digitalnum[5][3][10];

int main(void) 
{
	string str[5];

	string a[5] = { "","","","","" };
	a[0] += "### ..# ### ### #.# ### ### ### ### ###\n";
	a[1] += "#.# ..# ..# ..# #.# #.. #.. ..# #.# #.#\n";
	a[2] += "#.# ..# ### ### ### ### ### ..# ### ###\n";
	a[3] += "#.# ..# #.. ..# ..# ..# #.# ..# #.# ..#\n";
	a[4] += "### ..# ### ### ..# ### ### ..# ### ###\n";

	// 숫자 파싱
	for (int i = 0; i < 5; ++i) {
		int k = -1;
		for (int j = 0; j < (int)a[i].size(); ++j) {
			if (j % 4 == 0) {
				k++;
			}
			if (a[i][j] == ' ') continue;
			digitalnum[i][j - (4 * k)][k] = a[i][j];
		}
	}
	// 공백 포함 문자열 입력받음
	for (int i = 0; i < 5; ++i) {
		getline(cin, str[i]);
	}
	
	// 입력받은 문자 파싱
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 3; ++j) {
			num[i][j][0] = str[i][j];
		}
		for (int j = 4; j < 7; ++j) {
			num[i][j-4][1] = str[i][j];
		}
		for (int j = 8; j < 11; ++j) {
			num[i][j - 8][2] = str[i][j];
		}
		for (int j = 12; j < 15; ++j) {
			num[i][j - 12][3] = str[i][j];
		}
	}
	string ans = "";
	for (int h = 0; h < 4; ++h) {
		for (int k = 0; k < 9; ++k) {
			bool flag = true;
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (num[i][j][h] == '#' && digitalnum[i][j][k] == '.') {
						flag = false;
					}
				}
			}
			if (flag) {
				ans += k+'0';
				if (ans.size() == 2) {
					ans += ":";
				}
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}