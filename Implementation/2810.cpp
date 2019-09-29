#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	char input[51] = {}; cin >> input;

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] == 'S') res++;
		else {
			i++; res++;
		}
	}

	cout << res + (n != 1);

	return 0;
}