#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int x, int y)
{
	return x > y;
}

int main()
{
	int n;
	int songScore;
	int cut;

	cin >> n >> songScore >> cut;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		int score;
		cin >> score;
		vec.push_back(score);
	}
		
	sort(vec.begin(), vec.end(), comp);

	int bigger = 0;
	int same = 0;

	for (int i = 0; i < n; i++)
	{
		if (vec[i] > songScore)
			bigger++;
		else if (vec[i] == songScore)
			same++;
		else
			break;
	}

	if (bigger + same < cut)
		cout << bigger + 1;
	else
		cout << -1;
	return 0;
}