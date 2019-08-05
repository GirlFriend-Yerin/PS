#include <iostream>

using namespace std;

const int MAX = 1000000;

void eratos(bool arr[MAX + 1]) {

	arr[0] = arr[1] = true;
	for (int i = 2; i < MAX / 2 + 1; i++)
	{
		if (!arr[i])
		{
			for (int j = i * 2; j <= MAX; j += i)
				arr[j] = true;
		}
	}
}

int main()
{
	bool prime[MAX + 1] = {};

	eratos(prime);

	int to, des; cin >> to >> des;

	for (int i = to; i <= des; i++)
		if (!prime[i])
			cout << i << '\n';

	return 0;
}