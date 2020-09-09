#include <iostream>
#include <queue>

#define MAX 1000001

using namespace std;

int F, S, G, U, D;
bool visited[MAX];

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(S, 0));
	visited[S] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		int upnext = cur + U;	// 위층으로 올라갈때
		int downnext = cur - D;	// 아래층으로 내려갈때
		if (upnext <= F && upnext > 0 && !visited[upnext]) {
			if (upnext == G) {
				return cnt + 1;
			}
			q.push(make_pair(upnext, cnt + 1));
			visited[upnext] = true;
		}
		if (downnext <= F && downnext > 0 && !visited[downnext]) {
			if (downnext == G) {
				return cnt + 1;
			}
			q.push(make_pair(downnext, cnt + 1));
			visited[downnext] = true;
		}
	}
	return -1;	// 만약 갈 수있는 방법이 없으면 -1을 리턴
}

int main(void) {

	cin >> F >> S >> G >> U >> D;
	if (S == G) {	// 시작층이 도착층이라면
		cout << 0 << "\n";
	}
	else {
		int ret = bfs();

		if (ret < 0) {
			cout << "use the stairs" << "\n";
		}
		else {
			cout << ret << "\n";
		}
	}
	return 0;
}