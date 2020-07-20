#include <iostream>
#include <vector>

using namespace std;

int K, N;

long long getLAN(vector<long long>& LAN, long long mid)
{
	int lanSize = LAN.size();
	long long cnt = 0;
	for (int i = 0; i < lanSize; ++i) {
		cnt += (LAN[i] / mid);
	}
	return cnt;
}

int main(void)
{	
	cin >> K >> N;
	vector<long long> LAN(K);
	long long max = 0;
	for (int i = 0; i < K; ++i) {
		long long a;
		cin >> a;
		LAN[i] = a;
		if (max < LAN[i]) max = LAN[i];
	}

	long long left = 1;
	long long right = max;

	while (left  <= right) {
		long long mid = (left + right) / 2;	// 오버플로우 발생할 수 있으므로 long long 으로 해줘야함
		long long cnt = getLAN(LAN, mid);
		if (cnt < N) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << right << "\n";

	return 0;
}