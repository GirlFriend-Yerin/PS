#include <iostream>
#include <string.h>

using namespace std;

const short MAX = 30;

long long memo[MAX][MAX] = { 1, };
long long answer[MAX];

long long initAnswer(int wC, int hC) {

	// 알약이 1개 남거나, 완전한 알약이 없는 경우
	if ((wC == 1 && !hC) || !wC)
		return 1;

	long long& res = memo[wC][hC];
	if (res == -1) {
		res = 0;

		res += initAnswer(wC - 1, hC + 1);
		if (hC > 0)
			res += initAnswer(wC, hC - 1);
	}

	return res;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	for (int i = 0; i < MAX; i++)
		answer[i] = initAnswer(i, 1);

	int input;
	cin >> input;
	while (input) {
		cout << answer[input - 1] << '\n';
		cin >> input;
	}

	return 0;
}