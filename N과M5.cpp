#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> a;
bool visited[8];

void back_tracking(vector<int>& d, int cur) {
	d.push_back(a[cur]);
	visited[cur] = true;
	if (d.size() == M) {	// ������ ���̰� M�� �Ǹ�
		for (int i = 0; i < M; ++i) {
			cout << d[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {	// �湮�� ���ڴ� Ž������ �ʴ´�.
			back_tracking(d, i);
			d.pop_back();
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());	// ���������� ������ֱ� ����
	for (int i = 0; i < N; ++i) {
		fill(visited, visited + N, false);	// �湮 �迭 �ʱ�ȭ
		vector<int> d;
		back_tracking(d, i);
	}
	return 0;
}