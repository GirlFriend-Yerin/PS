#include <iostream>

using namespace std;

const int MAX = 200001;

int n;
char input[MAX];
short mapping[10];

int main()
{
	cin >> n >> input;

	for (int i = 0; i < 10; i++)
		cin >> mapping[i];

	for (int i = 0; i < n; i++) {
		int input_i = input[i] - '0';
		int convert = mapping[input_i - 1];

		input[i] = input_i > convert ? input_i + '0' : convert + '0';
	}

	cout << input;

	return 0;
}