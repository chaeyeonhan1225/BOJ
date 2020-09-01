#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class a {
public:
	int status;
	int value;
	a (int _status, int _value) {
		status = _status;
		value = _value;
	}
	
};

bool operator<(a _a, a _b) {
	if ( _a.value ==  _b.value) {	// ������ ������
		return _a.status > _b.status;	// ��ȣ�� - �ΰ� �� ��
	}
	else {
		return _a.value > _b.value;	// ������ ������ �� ��
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<a> pq;
	while (N--) {
		int x;
		cin >> x;
		if (x != 0) {
			if (x < 0) {
				pq.push(a(-1, -1 * x));
			}
			else {
				pq.push(a(1, x));
			}
		}
		else {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top().status * pq.top().value << "\n";
				pq.pop();
			}
		}
	}
}