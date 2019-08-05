#include <iostream>

using namespace std;

const int MAX = 300000;

int find(bool map[MAX], const int pos, const int& limits, const int& max)
{
	for (int i = 1; pos + i < max && i <= limits; i++) {
		if (map[pos + i])
			return i;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++)
	{
		int cities, potal, res = 0; cin >> cities >> potal;
		bool check[MAX] = {};

		for (int i = 0; i < cities; i++)
			cin >> check[i];

		int pos = 0;

		while (pos < cities) {
			int gate = find(check, pos, potal, cities);

			if (gate)
			{
				if (!check[pos])
					res++;

				pos += gate;
			}
			else
			{
				if (!check[pos])
					res++;

				if (pos + potal < cities)
				{
					pos += potal;
					check[pos] = true;
					res++;
				}
				else
					pos = cities;
			}
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}