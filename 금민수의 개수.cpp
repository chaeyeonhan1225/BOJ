#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findk(int a)
{
	string k = to_string(a);
	return k.length();
}

void goldminsu(char n, string &num, int k,vector<int> &min)
{
	num += n;
	if (num.length() == k) {
		min.push_back(stoi(num));
		return;
	}
	else {
		goldminsu('4', num, k, min);
		num.pop_back();
		goldminsu('7', num, k, min);
		num.pop_back();
		return;
	}
}
int main(void)
{
	int a, b;
	cin >> a >> b;
	int kb = findk(b);
	if (kb == 10)
		kb--;
	
	vector<int> min;
	
	for (int i = 1; i <= kb; ++i) {
		string num = "";
		goldminsu('4', num, i, min);
		num.clear();
		goldminsu('7', num,i,min);
	}
	int cnt = 0;
	for (auto &element : min) {
		if (element >= a && element <= b)
			cnt++;
	}

	cout << cnt << endl;
	
	return 0;
}