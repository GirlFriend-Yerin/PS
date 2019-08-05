/*
	2019 01 14
	14888 연산자 끼워넣기
	Brute force

	- 성공 -
*/

#include <iostream>

using namespace std;

const int MAX = 100;

int opers[4]; // 각 연산자의 갯수
int opnd[MAX]; // 피연산자
int useOper[4]; // 사용한 연산자의 수
int flag[MAX -1]; // 각 자리 연산자
int n;

int resMin = 1000000001, resMax = -1000000000;

void func(int pos)
{
	if (pos + 1 == n)
	{
		int sum = opnd[0];
		for (int i = 1; i < n; i++)
		{
			switch (flag[i - 1])
			{
			case 0:
				sum += opnd[i];
				break;
			case 1:
				sum -= opnd[i];
				break;
			case 2:
				sum *= opnd[i];
				break;
			case 3:
				sum /= opnd[i];
				break;
			}
		}

		if (resMin > sum)
			resMin = sum;
		if (resMax < sum)
			resMax = sum;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (useOper[i] + 1 <= opers[i])
			{
				if (i == 3 && opnd[pos + 1] == 0)
					continue;
				useOper[i]++;
				flag[pos] = i;
				func(pos + 1);
				useOper[i]--;
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> opnd[i];

	for (int i = 0; i < 4; i++)
		cin >> opers[i];

	func(0);

	cout << resMax << '\n' << resMin;

	return 0;
}