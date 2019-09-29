#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n; cin >> n;
	int sub = 1;
	
	for (int i = 2; i * i <= n; i++) {
		if (!(n % i)) {
			sub = n / i;
			break;
		}
	}
	
	cout << n - sub;

	return 0;
}