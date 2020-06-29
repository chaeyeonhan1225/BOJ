#include <iostream>
#include <string>
#define MAX 65

using namespace std;

int map[MAX][MAX];

string quadtree(int y, int x, int size)
{
	if (size == 1) {
		return to_string(map[y][x]);
	}
	int status = map[y][x];
	bool flag = false;
	for (int i = 0; i < size; ++i) {
		int j = 0;
		for (; j < size; ++j) {
			if (map[y+i][x+j] != status) {
				break;
			}
		}
		if (j == size) {
			flag = true;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		return to_string(status);
	}
	else {
		y = y + size;
		x = x + size;
		return "(" + quadtree(y - size, x - size, size / 2) + quadtree(y - size, x - size / 2, size / 2)
			+ quadtree(y - size / 2, x - size, size / 2) + quadtree(y - size / 2, x - size / 2, size / 2) + ")";
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << quadtree(0, 0, n) << endl;

	return 0;
}