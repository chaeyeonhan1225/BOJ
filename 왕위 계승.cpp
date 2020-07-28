#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> family;
map<string, double> d;

double dfs(string name) // dfs로 왕의 피가 얼마나 섞였는지 구한다.
{
	if (family[name].empty()) {
		return d[name];
	}
	string parent1 = family[name][0];
	string parent2 = family[name][1];
	double ret = (dfs(parent1) + dfs(parent2)) / 2;
	d[name] = ret;
	return ret;
}

void init(string king)	// 초기화
{
	for (auto element : d) {
		element.second = 0;
	}
	d[king] = 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	string king;
	cin >> king;
	
	for (int i = 0; i < N; ++i) {
		string child;
		string parent1, parent2;
		cin >> child >> parent1 >> parent2;
		family[child].push_back(parent1);
		family[child].push_back(parent2);
		d[child] = d[parent1] = d[parent2] = 0;
	}
	double ans = 0;
	string next = "";
	for (int i = 0; i < M; ++i) {
		string candidate;
		cin >> candidate;
		init(king);	// 초기화
		double temp = dfs(candidate);
		if (ans < temp) {
			ans = temp;
			next = candidate;
		}
	}
	cout << next << "\n";
	return 0;
}