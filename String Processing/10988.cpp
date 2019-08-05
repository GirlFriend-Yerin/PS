#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;  cin >> input;

	bool res = true;

	for (int left = 0, right = input.length() - 1; left <= right; left++, right--)
	{
		if (input[left] != input[right]) {
			res = false;
			break;
		}
	}

	cout << res;

	return 0;
}