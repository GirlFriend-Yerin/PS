#include <iostream>
#include <string>

using namespace std;

const short MAX = 10;

string result;

int main()
{
	char input[MAX + 1];
	string res;
	bool flag = false;

	cin >> input;

	int len = strlen(input);

	for (int i = 0; i < len; i++)
	{
		if (!flag)
		{
			if (input[i] < '3')
			{
				res += '0';
				flag = true;
			}
			else if (input[i] == '3')
				res += '3';
			else if (input[i] < '6')
			{
				res += '3';
				flag = true;
			}
			else if (input[i] == '6')
				res += '3';
			else if (input[i] < '9')
			{
				res += '6';
				flag = true;
			}
			else
				res += '9';
		}
		else
		{
			res += '9';
		}
	}
	
	cout << stoi(res);

	return 0;
}