#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int size = log10(n) + 1;
	int digits[10];

	for (int i = 0; i < size; i++)
	{
		digits[size - i - 1] = n % 10;
		n /= 10;
	}

	for (int i = 0; i < size; i++)
	{
		int max = i;

		for (int j = i; j < size; j++)
		{
			if (digits[j] > digits[max])
				max = j;
		}

		swap(digits[i], digits[max]);
	}

	for (int i = 0; i < size; i++)
		cout << digits[i];
}