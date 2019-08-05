#include <iostream>

using namespace std;

const short MAX = 100;

int main()
{
	char a[MAX + 1] = {}, oper, b[MAX + 1] = {};
	char res[MAX + MAX + 1] = {};

	cin >> a >> oper >> b;

	int aLen = 0;
	int bLen = 0;
	int aZero = 0;
	int bZero = 0;

	while (a[aLen] != '\0') {
		if (a[aLen] == '0')
			aZero++;
		aLen++;
	}

	while (b[bLen] != '\0') {
		if (b[bLen] == '0')
			bZero++;
		bLen++;
	}

	if (oper == '+') {
		if (aZero != bZero) res[0] = '1';
		else res[0] = '2';

		int totalLen = aLen < bLen ? bLen : aLen;

		for (int i = 1; i < totalLen; i++)
			res[i] = '0';

		if (aLen != bLen) {
			if (totalLen != aLen)
				res[totalLen - aLen] = '1';
			else
				res[totalLen - bLen] = '1';
		}
	}
	else {
		res[0] = '1';
		for (int i = 1; i <= aZero + bZero; i++)
			res[i] = '0';
	}

	cout << res;

	return 0;
}