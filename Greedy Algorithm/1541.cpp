/*
	2019 02 19
	1541 ÀÒ¾î¹ö¸° °ýÈ£
	Greedy Algorithm

	- ¼º°ø -
*/
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 50;
char input[MAX+1];

int main()
{
	cin >> input;

	stack<int> opnd;
	bool foundMinus = false;

	int digit = 0;
	char oper = '+';
	for (int i = 0; true; i++)
	{
		if (input[i] == 0)
		{
			if (foundMinus)
				digit *= -1;

			opnd.push(digit);

			while (opnd.size() > 1)
			{
				int opnd1 = opnd.top(); opnd.pop();
				int opnd2 = opnd.top(); opnd.pop();

				opnd.push(opnd1 + opnd2);
			}
			break;
		}
		else if ('0' <= input[i] && input[i] <= '9')
			digit = (digit * 10) + (input[i] - '0');
		else
		{
			oper = input[i];

			if (foundMinus)
				digit *= -1;

			if (oper == '-')
				foundMinus = true;

			opnd.push(digit);
			digit = 0;
		}
	}

	cout << opnd.top(); 

	return 0;
}