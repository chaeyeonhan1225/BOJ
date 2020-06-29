#include <iostream>
#include <string>

using namespace std;

bool isEmpty(int name[])
{
	for (int i = 0; i < 26; ++i) {
		if (name[i] > 0)
			return false;
	}
	return true;
}

char isOdd(int name[])
{
	for (int i = 0; i < 26; ++i) {
		if (name[i] % 2 == 1)
			return 'A'+i;
	}
	return ' ';
}
bool isPalindrome(string &ret)
{
	for (int i = 0; i < (int)ret.length() / 2; ++i) {
		if (ret[i] != ret[(int)ret.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	int name[26];
	for (int i = 0; i < 26; ++i)
		name[i] = 0;
	string hansuname;
	cin >> hansuname;
	for (int i = 0; i < (int)hansuname.length(); ++i) {
		name[hansuname[i]-'A']++;
	}
	string palindrome = "";
	char m = isOdd(name);
	if(m!=' ')
		name[(int)(m - 'A')]--;
	while (!isEmpty(name)) {
		for (int i = 0; i < 26; ++i) {
			if (name[i] > 0) {
				for(int j=0;j<name[i]/2;++j)
					palindrome += (char)('A' + i);
				name[i] -= name[i]/2;
			}
		}
		for (int i = 25; i >= 0; --i) {
			if (name[i] > 0) {
				for(int j=0;j<name[i];++j)
					palindrome += (char)('A' + i);
				name[i] = 0;
			}
		}
	}

	string ret = "";
	for (int i = 0; i < (int)palindrome.length() / 2; ++i) {
		ret += palindrome[i];
	}
	if (m != ' ')
		ret += m;
	for (int i = (int)palindrome.length() / 2; i < (int)palindrome.length(); ++i) {
		ret += palindrome[i];
	}
	
	if (isPalindrome(ret))
		cout << ret << endl;
	else
		cout << "I'm Sorry Hansoo" << endl;
	
	return 0;
}