#include <iostream>

using namespace std;

int main()
{
	int num[3];

	for (int i = 0; i < 3; i++)
		cin >> num[i];

	for (int i = 0; i < 3; i++)
	{
		int min = i;
		for (int j = i; j < 3; j++)
			if (num[j] < num[min])
				min = j;
		
		int temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}

	int dif[2] = { num[1] - num[0], num[2] - num[1] };

	if (dif[0] == dif[1])
		cout << num[2] + dif[1];
	else if (dif[0] < dif[1])
		cout << num[2] - dif[0];
	else
		cout << num[1] - dif[1];

	return 0;
}