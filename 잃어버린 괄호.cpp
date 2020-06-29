#include <iostream>
#include <string>
#include <vector>

using namespace std;

int plus_str(string s)
{
	int sum = 0;
	while (1) {
		
		if (s[0] == '+')
			s.erase(0, 1);
		int i = s.find("+");

		if (i >= 0) {
			string num = s.substr(0, i);
			sum += stoi(num);
			s.erase(0, i);
		}
		else {
			sum += stoi(s);
			break;
		}
	}
	return sum;
}

int main(void)
{
	string f;
	vector<string> sn;

	cin >> f;
	
	while (1) {
		if (f[0] == '-')
			f.erase(0, 1);	//	-¾ø¾Ö±â
		int s = 0;
		int e = f.find("-");
		if (e < 0) {
			sn.push_back(f);
			break;
		}
		else {
			sn.push_back(f.substr(s, e));
		}
		f.erase(s, e);
	}
	int ans = plus_str(sn[0]);
	
	for (int i = 1; i < (int)sn.size(); ++i) {
		ans -= plus_str(sn[i]);
	}

	cout << ans << endl;

	return 0;
}