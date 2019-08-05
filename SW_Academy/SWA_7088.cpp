#include <iostream>

using namespace std;

const int MAX = 100001;

void fenwikAdd(int bound, int value, int* source)
{
	for (; value <= bound; value += value & (-value))
		source[value]++;
}

int fenwikSum(int value, int* source)
{
	int res = 0;
	for (; value; value -= value & (-value))
		res += source[value];

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int i = 1; i <= tcc; i++)
	{
		int* res[3];

		for (int j = 0; j < 3; j++)
			res[j] = new int[MAX];

		int calfCount, queires;

		cin >> calfCount >> queires;

		for (int j = 0; j < 3; j++)
			for (int k = 0; k < calfCount+1; k++)
				res[j][k] = 0;

		for (int j = 0; j < calfCount; j++)
		{
			int val; cin >> val;
			fenwikAdd(calfCount, j + 1, res[val - 1]);
		}

		cout << '#' << i << '\n';

		for (int j = 0; j < queires; j++)
		{
			int to, des;

			cin >> to >> des;

			for (int k = 0; k < 3; k++)
			{
				int desSum = fenwikSum(des, res[k]);
				int toSum = fenwikSum(to - 1, res[k]);

				cout << desSum - toSum << ' ';
			}
			cout << '\n';
		}

		for (int j = 0; j < 3; j++)
			delete[] res[j];
	}

	return 0;
}