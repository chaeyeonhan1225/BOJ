#include <iostream>
#include <map>
#include <string>

using namespace std;

string getParent(map<string, string>& network, string x)
{
	if (network[x] == x) return x;
	return network[x] = getParent(network, network[x]);
}

int unionParent(map<string, string>& network,map<string,int>& ans, string a, string b)
{
	a = getParent(network, a);
	b = getParent(network, b);
	if (a == b) {
		return ans[a];
	} 
	else if (a < b) {	// 사전순으로 작은 key를 노드로
		network[b] = a;
		ans[a] += ans[b];
		return ans[a];
	}
	else {
		network[a] = b;
		ans[b] += ans[a];
		return ans[b];
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		map<string, string> network;
		map<string, int> ans;
		for (int i = 0; i < f; ++i) {
			string a;
			string b;
			cin >> a;
			cin >> b;
			if (network.find(a) == network.end()) {
				network[a] = a;
				ans[a] = 1;
			}
			if (network.find(b) == network.end()) {
				network[b] = b;
				ans[b] = 1;
			}
			cout << unionParent(network, ans, a, b) << "\n";
		}
	}
	return 0;
}