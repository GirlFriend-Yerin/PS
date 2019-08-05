#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4000000;

bool prime[MAX + 1] = { true, true };

vector<int> primes;

void eratos() {

	for (int i = 2; i <= MAX; i++)
	{
		if (!prime[i])
		{
			primes.push_back(i);

			for (int j = i * 2; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}

int main()
{
	eratos();

	int n; cin >> n;
	int res = 0;

	int left = 0, right = 0;
	int subSum = 0;

	while (right < primes.size()) {
		if (subSum >= n) subSum -= primes[left++];
		else if (right > n) break;
		else subSum += primes[right++];
		if (subSum == n) res++;
	}

	cout << res;

	return 0;
}