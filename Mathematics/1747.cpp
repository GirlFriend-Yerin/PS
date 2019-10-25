#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalin(int val) {

	string str = to_string(val);
	int len = str.length(); 

	for (int i = 0; i < len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return false;
	return true;
}

bool isPrime(int val) {
	int max = sqrt(val) + 1;
	for (int i = 2; i < max; i++)
		if (!(val % i)) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int res = 0;
	for (int i = n; i <= 1003001; i++) {
		if (i == 1) continue;
		if (isPalin(i) && isPrime(i)) {
			cout << i;
			break;
		}
	}

	return 0;
}