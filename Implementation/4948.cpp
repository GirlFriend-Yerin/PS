#include <iostream>

using namespace std;

const int MAX = 50000;

int prime[MAX];
int primeCount;

void eratos() {
	const int max = 123456 * 2 * 2;
	bool check[max + 1] = {true, true};

	for (int i = 2; i < max + 1; i++) {
		if (!check[i]) {
			prime[primeCount++] = i;
			for (int j = 2; i * j < max + 1; j++)
				check[i * j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	eratos();

	int val; cin >> val;
	while (val) {
		int res = 0;
		
		int str = 0;
		while (prime[str] <= val)
			str++;

		for (int i = str; prime[i] <= (2 * val); i++)
			res++;

		cout << res << '\n';

		cin >> val;
	}

	return 0;
}