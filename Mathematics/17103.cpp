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

	int tcc;
	cin >> tcc;

	while (tcc--)
	{
		int tar;
		int res = 0;

		cin >> tar;

		for (int i = 0; primeList[i] < tar; i++)
			if (tar - primeList[i] >= primeList[i] && !isPrime[tar - primeList[i]])
				res++;

		cout << res << '\n';
	}

	return 0;
}