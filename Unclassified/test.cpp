#include <iostream>
#include <vector>

using namespace std;

int len;
int leftMax;

int checkSummer(vector<int> &T, int startPos) {
	int max = -1;

	int summerMax = leftMax;

	for (int j = startPos; j < len; j++)
	{
		if (summerMax < T[j])
			summerMax = T[j];

		if (leftMax >= T[j])
		{
			leftMax = summerMax;
			return j;
		}
	}

	return -1;
}

int solution(vector<int> &T) {
	int res = 0;

	len = T.size();
	leftMax = T[res];
	
	int cnt = 0;
	while (res < len)
	{
		while (res + cnt < len && leftMax >= T[res + cnt])
			cnt++;

		res += cnt;

		int summer = checkSummer(T, res);
		if (summer != -1)
			res = summer;
		else
			break;
		cnt = 0;
	}
	
	return res;
}

int main()
{
	vector<int> a;
	int n;

	cin >> n;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solution(a);

	return 0;
}