#include <iostream>

using namespace std;

bool isHarshad(int num)
{
	int digitSum = 0;

	for (int i = num; i; i /= 10)
		digitSum += i % 10;

	return num % digitSum;
}

int main()
{
	int n;

	cin >> n;

	for (; isHarshad(n); n++);

	cout << n;

	return 0;
}