/*
	2019 04 23
	2217 로프
	그리디 알고리즘

	- 성공 -
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> ropes;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ropes.resize(n);

	for (int i = 0; i < n; i++)
		cin >> ropes[i];

	sort(ropes.begin(), ropes.end());

	priority_queue<int> heap;

	for (int i = 0; i < n; i++)
		heap.push(ropes[i] * (n - i));

	cout << heap.top();

	return 0;
}