#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> s(n);

	for (int i = 0; i < n; i++)
		cin >> s[i];

	int answer = 0;
	int counter[5] = {};

	for (int i = 0; i < s.size(); i++) {
		counter[s[i]]++;
	}

	answer += counter[4];
	answer += counter[2] / 2;
	counter[2] %= 2;

	int oneNthree = counter[1] < counter[3] ? counter[1] : counter[3];

	answer += oneNthree;
	counter[1] -= oneNthree; counter[3] -= oneNthree;

	answer += counter[3]; counter[3] = 0;

	if (counter[2])
	{
		if (counter[1] > 2) {
			counter[1] -= 2;
		}
		answer++;
	}

	answer += counter[1] / 4;
	counter[1] %= 4;

	if (counter[1] > 0)
		answer++;

	cout<< answer;

	return 0;
}