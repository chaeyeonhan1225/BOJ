#include <iostream>

using namespace std;

int main(void)
{
	int t;
	int f[12];

	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	// Á¡È­½Ä f[n] = f[n-1] + f[n-2] + f[n-3]
	for (int n = 4; n < 12; ++n)
		f[n] = f[n - 1] + f[n - 2] + f[n - 3];

	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	
	return 0;
}