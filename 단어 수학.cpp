#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// first�� ū ������� ����
bool compare(pair<long long, char>& a, pair<long long, char>& b) {
	if (a.first > b.first) {
		return true;
	}
	else {
		return false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	
	long long d[26];

	for (int i = 0; i < 26; ++i) {
		d[i] = 0;
	}

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		// ���׽� ���·� �ٲ��ش�.
		for (int i = str.length()-1; i >= 0; --i) {
			int k = str.length() - i - 1;
			d[str[i] - 'A'] += pow(10, k);
		}
	}

	vector<pair<long long, char>> temp;
	for (int i = 0; i < 26; ++i) {
		temp.push_back(make_pair(d[i], 'A' + i));
	}

	// ������������ ����
	sort(temp.begin(), temp.end(),compare);

	long long ans = 0;
	int k = 9;
	
	// ū ������� 9���� �Ҵ����ش�.
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i].first == 0) break;
		ans += d[temp[i].second - 'A'] * k--;
	}
	
	cout << ans << "\n";
	
	return 0;
}