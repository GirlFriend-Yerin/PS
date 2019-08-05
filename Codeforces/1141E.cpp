/*
	2019 04 02
	1141E Superhero Battles
	Math

	- Success - 6 Submission
*/

#include <iostream>

using namespace std;

const int MAX = 200000;

int damage[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long hp;
	int n;
	long long res = 0;
	long long maxDamagePerTurn = 0, dpt = 0;

	cin >> hp >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> damage[i];
		dpt += damage[i];
		if (dpt < maxDamagePerTurn)
			maxDamagePerTurn = dpt;
	}

	if (dpt >= 0)
	{
		if (hp + maxDamagePerTurn > 0)
			res = -1;
		else
		{
			for (; hp > 0; res++)
				hp += damage[res];
		}
	}
	else
	{
		hp += maxDamagePerTurn;

		if (hp < 0)
		{
			hp -= maxDamagePerTurn;
			for (; hp > 0; res++)
				hp += damage[res];
		}
		else
		{
			long long head = hp / -dpt;
			res = (head == 0 ? 1 : head)  * n;
			long long accDamage = (head == 0 ? 1 : head) * -dpt;
			hp -= maxDamagePerTurn;

			for (int i = 0; hp > accDamage; i++)
			{
				res++;
				accDamage += -damage[i % n];
			}
		}
	}

	cout << res;

	return 0;
}