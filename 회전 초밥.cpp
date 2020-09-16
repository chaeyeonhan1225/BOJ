#include <iostream>
#include <vector>
#define MAX 3001

using namespace std;

int menu[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int d;
	int k;
	int c;
	cin >> N >> d >> k >> c;
	vector<int> dish;

	for (int i = 0; i < N; ++i) {
		int s;
		cin >> s;
		dish.push_back(s);
	}

	for (int i = 0; i < N; ++i){
		dish.push_back(dish[i]);
	}

	int end = k;
	int cnt = 0;
	int max = 0;
	for (int i = 0; i < k; ++i) {
		if (menu[dish[i]] == 0) cnt++;
		menu[dish[i]]++;
		int ans = cnt;
		if (menu[c] == 0) ans++;
		if (max < ans) max = ans;
	}

	for (int start = 1; start < N; ++start) {
		end++;
		menu[dish[start - 1]]--;
		if(menu[dish[start - 1]]==0) cnt--;	// �����ȿ� ��ġ�� �޴��� ������ 
		if (menu[dish[end - 1]] == 0) cnt++;	// �����ȿ� ��ġ�� �޴��� ������
		menu[dish[end-1]]++;
		int ans = cnt;
		if (menu[c] == 0) ans++;	// ������ �Ἥ �ϳ� �� ���� �� �ִٸ�
		if (max < ans) max = ans;
	}

	cout << max << "\n";
	
	return 0;
}