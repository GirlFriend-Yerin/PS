#include <iostream>
#include <string>

using namespace std;

string input;

int search(bool upper, int pos, int count)
{
	if (upper) {
		if (input[pos + 1] == '\0')
			return count;
		else
		{
			if (input[pos] + 1 == input[pos + 1])
				return search(upper, pos + 1, count + 1);
			else
				return count;
		}
	}
	else {
		if (input[pos + 1] == '\0')
			return count;
		else
		{
			if (input[pos] - 1 == input[pos + 1])
				return search(upper, pos + 1, count + 1);
			else
				return count;
		}
	}
}

int main()
{
	cin >> input;
	int res = 0;

	for (int i = 0; i < input.size() - 1;)
	{
		int diff = input[i + 1] - input[i];

		if (diff == 1)
		{
			int cnt = search(true, i, 1);
			if (cnt == 3)
				res++;
			i += cnt;
		}
		else if (diff == -1)
		{
			int cnt = search(false, i, 1);
			if (cnt == 3)
				res++;
			i += cnt;
		}
		else
			i++;
	}

	cout << res;

	return 0;
}