#include <iostream>

using namespace std;

const int MAX = 3 * 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	char input[MAX + 1];

	cin >> n >> input;

	int strPoint = n - 1;
	int leftPoint = 0;

	for (; strPoint > 0 && input[strPoint] >= input[0]; strPoint--);

	if (strPoint == 0)
		cout << "NO";
	else
	{

	}


	return 0;
}