/*
	2019 01 17
	1475 방번호
	MatheMatics

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	short digits[10] = {};
	char room[8] = {};
	int package = 0;
	
	cin >> room;

	for (int i = 0; i < (sizeof(room) / sizeof(char)); i++)
	{
		if (room[i] == '6' || room[i] == '9')
		{
			if (digits[6] < digits[9])
				digits[6]++;
			else
				digits[9]++;
		}
		else
			digits[room[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
		if (package < digits[i])
			package = digits[i];

	cout << package;
		
	return 0;
}