#include <iostream>

using namespace std;

int worms[21] = { 1, 1, 2, 4 };

void init(int n)
{
	for (int j = 4; j <= n; j++)
	{
		for (int i = 0; i < j; i++) {
			//Â¦¼ö ÇØ
			if (i % 2) {
				if (i + 4 < j)
					worms[i] = 0;
			}
			//È¦¼ö ÇØ
			else {
				if (i + 3 < j)
					worms[i] = 0;
			}
		}

		int val = 0;
		for (int i = 0; i < j; i++)
			val += worms[i];

		worms[j] = val;
	}
}

int main()
{
	int n; cin >> n;

	init(n);

	cout << worms[n] << endl;

	return 0;
}