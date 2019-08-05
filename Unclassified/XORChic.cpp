#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input; cin >> input;
	int key = input[0] ^ 'C';

	string res;
	for (int i = 0; i < input.length(); i++)
		res += input[i] ^ key;

	cout << res;

	return 0;
}