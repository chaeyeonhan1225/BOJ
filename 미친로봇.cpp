#include <iostream>
#include <vector>
#define MAX 31

using namespace std;

double p[4];
bool visited[MAX][MAX];
double ans = 0;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

void dfs(int N,int y,int x,int cnt,double d) {
	visited[y][x] = true;
	if (cnt == N) {
		ans += d;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx]) {
			dfs(N, ny, nx, cnt+1,d*p[i]);
			visited[ny][nx] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	scanf("%d", &N);
	scanf("%lf%lf%lf%lf", &p[0], &p[1], &p[2], &p[3]);
	for (int i = 0; i < 4; ++i) {
		p[i] = p[i] / 100.0;
	}
	// 초기위치 
	visited[15][15] = true;
	dfs(N, 15, 15, 0, 1);
	// 절대/상대 오차
	printf("%.11lf",ans);

	return 0;
}