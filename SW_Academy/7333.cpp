#include <iostream>

using namespace std;

const short MAX = 100;

short under[MAX];
short over[MAX];
short underCount, overCount;

void sortingArray()
{
	for (int i = 0; i < underCount; i++)
	{
		short min = i;
		for (int j = i; j < underCount; j++)
			if (under[min] > under[j])
				min = j;
		
		short temp = under[min];
		under[min] = under[i];
		under[i] = temp;
	}

	for (int i = 0; i < overCount; i++)
	{
		short min = i;
		for (int j = i; j < overCount; j++)
			if (over[min] > over[j])
				min = j;

		short temp = over[min];
		over[min] = over[i];
		over[i] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;

	cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++)
	{
		underCount = overCount = 0;
		int n;
		int res = 0;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;

			if (val < 25)
				under[underCount++] = val;
			else
				over[overCount++] = val;
		}

		sortingArray();

		int overPivot = 0, underPivot = 0;

		for (; overPivot < overCount && underPivot < underCount; res++, overPivot++, underPivot++);

		if (overPivot == overCount)
		{
			for (int toBottom = underCount - 1; underPivot < toBottom; toBottom--)
			{
				for (int cnt = 1; under[toBottom] * cnt < 50; cnt++, underPivot++);
				res++;
			}
		}
		else
		{
			for (int toBottom = overCount - 1; overPivot < toBottom; toBottom--)
			{
				if (over[toBottom] >= 50)
					res++;
				else
				{
					overPivot++;
					res++;
				}
			}
		}

		cout << '#' << tc << ' ' << res << '\n';
	}
}