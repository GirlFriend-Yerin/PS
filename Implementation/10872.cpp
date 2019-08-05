#include <iostream>

using namespace std;

long long facto[13] = { 1 };

int main()
{
	for (int i = 1; i < 13; i++)
		facto[i] = facto[i - 1] * i;

	int n; cin >> n;

	cout << facto[n];

	return 0;
}