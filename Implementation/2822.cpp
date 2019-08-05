#include <iostream>

using namespace std;

struct Data {
	int origin;
	int data;
};

int main()
{
	Data input[8];

	for (int i = 0; i < 8; i++) {
		input[i].origin = i + 1;
		cin >> input[i].data;
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int max = i;
		for (int j = i + 1; j < 8; j++) {
			if (input[max].data < input[j].data)
				max = j;
		}
		swap(input[max], input[i]);
		sum += input[i].data;
	}

	cout << sum << '\n';
	for (int i = 0; i < 5; i++) {
		int min = i;
		for (int j = i + 1; j < 5; j++) {
			if (input[min].origin > input[j].origin)
				min = j;
		}
		swap(input[min], input[i]);
		cout << input[i].origin << ' ';
	}

	return 0;
}