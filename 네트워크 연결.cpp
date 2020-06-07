#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

// n: ��ǻ���� ��, m: ������ �� �ִ� ���� ��
int n, m;
int parent[MAX];

// ���� Ŭ����
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int _distance)
	{
		node[0] = a;
		node[1] = b;
		distance = _distance;
	}

	bool operator<(Edge &edge)
	{
		return distance < edge.distance;
	}
};

// ������ ���� ����
vector<Edge> network;

int getParent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int findMin()
{
	int sum = 0;
	for (int i = 0; i < (int)network.size(); ++i) {
		if (!findParent(network[i].node[0], network[i].node[1])) {
			sum += network[i].distance;
			unionParent(network[i].node[0], network[i].node[1]);
		}
	}
	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// �θ� ��� �ʱ�ȭ
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		int c;
		cin >> a >> b >> c;
		network.push_back(Edge(a, b, c));
	}

	// �Ÿ� ������ �������� ����
	sort(network.begin(), network.end());

	cout << findMin() << "\n";

	return 0;
}