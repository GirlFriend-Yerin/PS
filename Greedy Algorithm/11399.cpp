/*
	2019 01 15
	11399 ATM
	Greedy Algorithm

	- ¼º°ø -
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int timeTable[1000];
	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		scanf("%d", &timeTable[i]);

	// Selection Sort

	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
			if (timeTable[min] > timeTable[j])
				min = j;
		swap(timeTable[i], timeTable[min]);
	}
	
	for (int i = 1; i < n; i++)
		timeTable[i] += timeTable[i-1];

	for (int i = 0; i < n; i++)
		sum += timeTable[i];

	cout << sum;

	return 0;
}
