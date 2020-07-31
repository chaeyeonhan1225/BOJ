#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
	vector<pair<int, int>> Edge;	// 간선 정보
	map<int, int> inDegree;	// 진입 간선 수
	set<int> node;	// 노드
	int t = 0;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		else if (a == 0 && b == 0) {
			bool flag = true;
			int root = 0;
			for (auto element : node) {
				if (inDegree.find(element) == inDegree.end()) {
					root++;
				}
				else {
					if (inDegree[element] != 1) {	// 진입간선수가 1개 보다 많다면
						flag = false;
					}
				}
			}
			if (root > 1) flag = false;	// 루트가 1개보다 더 많으면
			if (Edge.size() + 1 != node.size()) flag = false;	// 간선의 수+1 != 노드의 수 라면
			t++;
			if (flag) {
				cout << "Case " << t << " is a tree." << "\n";
			}
			else if (node.size() == 0) {
				cout << "Case " << t << " is a tree." << "\n";
			}
			else {
				cout << "Case " << t << " is not a tree." << "\n";
			}

			Edge.clear();
			node.clear();
			inDegree.clear();
			continue;
		}
		node.insert(a);
		node.insert(b);
		Edge.push_back(make_pair(a, b));
		if (inDegree.find(b) == inDegree.end()) {
			inDegree[b] = 0;
		}
		inDegree[b]++;

	}
	return 0;
}