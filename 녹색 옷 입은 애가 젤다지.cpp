#include <iostream>
#include <queue>
#include <tuple>
#define MAX 126
#define INF 200000000

using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int main(void)
{
	int k = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int map[MAX][MAX];
		int d[MAX][MAX];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				d[i][j] = INF;
			}
		}
		
		d[0][0] = map[0][0];
		priority_queue<tuple<int, int, int>> pq;
		pq.push(make_tuple(-1*d[0][0], 0, 0));
		while (!pq.empty()) {
			int currentY = get<1>(pq.top());
			int currentX = get<2>(pq.top());
			int distance = -1 * get<0>(pq.top());
			pq.pop();
			if (distance > d[currentY][currentX]) continue;
			for (int i = 0; i < 4; ++i) {
				int ny = currentY + dy[i];
				int nx = currentX + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
					int nextDistance = distance + map[ny][nx];
					if (nextDistance < d[ny][nx]) {
						d[ny][nx] = nextDistance;
						pq.push(make_tuple(-1 * nextDistance, ny, nx));
					}
				}
			}
		}
		cout << "Problem " << k++ << ": " << d[n - 1][n - 1] << "\n";
	}
	return 0;
}