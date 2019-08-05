/*
	2019 01 27
	2864 5와 6의 차이
	MatheMatics

	- 성공 -
*/
#include <iostream>
#include <string>

using namespace std;

string change(string s, char target, char val)
{
	string ret = s;
	for (int i = 0; i < ret.length(); i++)
		if (ret[i] == target)
			ret[i] = val;

	return ret;
}

int main()
{
	string left, right;
	int resMin, resMax;
	cin >> left >> right;

	resMin = stoi(change(right, '6', '5')) + stoi(change(left, '6', '5'));
	resMax = stoi(change(right, '5', '6')) + stoi(change(left, '5', '6'));

	cout << resMin << ' ' << resMax;

	return 0;
}