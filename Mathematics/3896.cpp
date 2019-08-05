#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1299709;

bool prime[MAX + 1] = { true, true };
vector<int> primes;

void eratos() {

	for (int i = 2; i <= MAX; i++)
	{
		if (!prime[i])
		{
			primes.push_back(i);
			for (int j = i * 2; j <= MAX; j += i)
				prime[j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int n; cin >> n;

	eratos();

	for (int i = 0; i < n; i++) {
		int input; cin >> input;

		if (!prime[input])
			cout << 0 << '\n';
		else
		{
			int pos = 0; while (primes[pos + 1] < input) pos++;

			cout << primes[pos + 1] - primes[pos] << '\n';
		}

	}


	return 0;
}