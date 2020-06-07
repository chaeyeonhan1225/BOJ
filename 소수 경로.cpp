#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

bool prime[10001];
bool visited[10001];


void init(queue<pair<string, int>> &q, string& first,int cnt)
{
	for (int i = 1; i <= 9; ++i) {
		string k = "";
		k += to_string(i);
		k += first[1];
		k += first[2];
		k += first[3];
		if(!visited[stoi(k)]&&!prime[stoi(k)])
			q.push(make_pair(k, cnt));
		visited[stoi(k)] = true;
	}
	for (int i = 0; i <= 9; ++i) {
		string k = "";
		k += first[0];
		k += to_string(i);
		k += first[2];
		k += first[3];
		if (!visited[stoi(k)] && !prime[stoi(k)])
			q.push(make_pair(k, cnt));
		visited[stoi(k)] = true;
	}
	for (int i = 0; i <= 9; ++i) {
		string k = "";
		k += first[0];
		k += first[1];
		k += to_string(i);
		k += first[3];
		if (!visited[stoi(k)] && !prime[stoi(k)])
			q.push(make_pair(k, cnt));
		visited[stoi(k)] = true;
	}
	for (int i = 0; i <= 9; ++i) {
		string k = "";
		k += first[0];
		k += first[1];
		k += first[2];
		k += to_string(i);
		if (!visited[stoi(k)] && !prime[stoi(k)])
			q.push(make_pair(k, cnt));
		visited[stoi(k)] = true;
	}
}

int bfs(int a, int b)
{
	queue<pair<string, int>> q;
	string ans = to_string(b);
	string first = to_string(a);
	init(q, first,1);
	while (!q.empty()) {
		string f = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (f == ans) {
			return cnt;
		}
		else {
			init(q, f, cnt + 1);
		}
	}
	return -1;
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 2; i <= 10001; ++i) {
		for (int j = 2; j <= 10001/i; ++j) {
			if (!prime[i*j]) {
				prime[i*j] = true;
			}
		}
	}
	
	while (t--) {
		int a;
		int b;
		cin >> a >> b;
		int ans = bfs(a, b);
		if (a == b) {
			cout << 0 << endl;
		}
		else if (ans < 0) {
			cout << "Impossible" << endl;
		}
		else {
			cout << ans << endl;
		}
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}