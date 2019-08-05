/*
	2019 03 30
	1037 약수
	Mathematics

	- 성공 -
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const short MAX = 50;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count;
	int res = 0;
	vector<int> childList;
	cin >> count;
	
	childList.resize(count);

	for (int i = 0; i < count; i++)
		cin >> childList[i];

	sort(childList.begin(), childList.end());

	if (count % 2)
		res = childList[count / 2] * childList[count / 2];
	else
		res = childList[0] * childList[count-1];

	cout << res;

	return 0;
}