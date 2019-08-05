/*
	2019 01 12
	1026 보물
	Sorting

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	int n;
	int a[50];
	int b[50];
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	// Selection Sort
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(a[min], a[i]);
	}

	// Selection Sort
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i; j < n; j++)
			if (b[max] < b[j])
				max = j;
		swap(b[max], b[i]);
	}

	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	cout << sum;

	return 0;
}