/*
	2019 02 10
	14891 톱니바퀴
	Simulation

	- 성공 -
*/
#include <iostream>

using namespace std;

const short MAX = 8;

char gear[4][MAX+1];
short gearsLeft[4] = { 6, 6, 6, 6 };
short gearsRight[4] = { 2, 2, 2, 2 };

void turn(int pos, bool isRight, int* check) // true - 시계방향, false - 반시계 방향
{
	check[pos] = isRight ? 1 : -1;

	if (pos < 3 && gear[pos][gearsRight[pos]] != gear[pos + 1][gearsLeft[pos + 1]] && !check[pos + 1])
		turn(pos + 1, !isRight, check);
	if (pos > 0 && gear[pos][gearsLeft[pos]] != gear[pos - 1][gearsRight[pos - 1]] && !check[pos - 1])
		turn(pos - 1, !isRight, check);

}

int main()
{
	int tcc, sum = 0;
	
	for (int i = 0; i < 4; i++)
		cin >> gear[i];

	cin >> tcc;

	while (tcc--)
	{
		int chain, order;
		int checker[4] = {};

		cin >> chain >> order;

		if (order == -1)
			turn(chain - 1, false, checker);
		else
			turn(chain - 1, true, checker);

		for (int i = 0; i < 4; i++)
		{
			if (!checker[i])
				continue;

			if (checker[i] == 1) // Right
			{
				gearsRight[i] = (gearsRight[i] == 0) ? 7 : (gearsRight[i] - 1);
				gearsLeft[i] = (gearsLeft[i] == 0) ? 7 : (gearsLeft[i] - 1);
			}
			else // Left
			{
				gearsRight[i] = (gearsRight[i] + 1) % MAX;
				gearsLeft[i] = (gearsLeft[i] + 1) % MAX;
			}
		}
	}

	for (int i = 0, score = 1; i < 4; i++, score *= 2)
	{
		// cout << i + 1 << " : " << (gearsLeft[i] + 2) % MAX << '\n'; // For Debug

		if (gear[i][(gearsLeft[i] + 2) % MAX] == '1')
			sum += score;
	}

	cout << sum;

	return 0;
}