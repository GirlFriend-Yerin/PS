#include <iostream>
#include <cmath>

using namespace std;

short bizCount;
short biz[31];
short flag[31]; // 0 - 오른쪽, 1 - 왼쪽 , 2 - 안올림
bool isGo;

void func(int pos, int weight)
{
	if (pos != bizCount)
	{
		if (biz[pos] == weight)
			isGo = false;
		else
		{
			int sum = 0;
			for (int i = 0; i <= pos; i++)
			{
				if (flag[i] == 0)
					sum += biz[i];
				else if (flag[i] == 1)
					sum -= biz[i];
			}

			if (abs(sum) != weight)
			{
				for (int i = 0; i < 3; i++)
				{
					if (isGo)
					{
						flag[pos] = i;
						func(pos + 1, weight);
					}
				}
			}
			else
				isGo = false;
		}
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < pos; i++)
		{
			if (flag[i] == 0)
				sum += biz[i];
			else if (flag[i] == 1)
				sum -= biz[i];
		}

		if (abs(sum) == weight)
			isGo = false;
	}
}

int main()
{
	int tcc;

	cin >> bizCount;

	for (int i = 0; i < bizCount; i++)
		cin >> biz[i];

	cin >> tcc;
	for (int i = 0; i < tcc; i++)
	{
		short weight;
		cin >> weight;
		isGo = true;
		if (weight > 500 * bizCount)
			cout << "N ";
		else
		{
			func(0, weight);
			if (isGo)
				cout << "N ";
			else
				cout << "Y ";
		}
			
	}

	return 0;
}