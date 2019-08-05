#include <iostream>

using namespace std;

const int MAX = 1000000;
const int PRIMEMAX = 79498;

bool isPrime[MAX + 1];
int primeList[PRIMEMAX];
int primeCount;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < MAX; i++)
	{
		if (!isPrime[i])
		{
			primeList[primeCount++] = i;
			for (int j = 2; j * i < MAX; j++)
				isPrime[j * i] = true;
		}
	}

	while (true)
	{
		int tar;
		int res;

		cin >> tar;

		if (!tar)
			break;

		for (res = 1; res < primeCount && primeList[res] < tar; res++)
			if (!isPrime[tar - primeList[res]])
				break;

		if (res == primeCount || primeList[res] >= tar)
			cout << "Goldbach's conjecture is wrong.";
		else
			cout << tar << " = " << primeList[res] << " + " << tar - primeList[res] << '\n';
	}

	return 0;
}