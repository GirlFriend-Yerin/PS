#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char opnd1[MAX + 1] = {}, opnd2[MAX + 1] = {};
	int carry[MAX + 1] = {};
	char result[MAX + 2] = {};
	int op1Len, op2Len;

	cin >> opnd1 >> opnd2;

	op1Len = strlen(opnd1); op2Len = strlen(opnd2);

	for (int i = 0; opnd1[i] || opnd2[i]; i++)
	{
		if (opnd1[i])
			opnd1[i] -= '0';
		if (opnd2[i])
			opnd2[i] -= '0';
	}

	int strPos = op1Len > op2Len ? op1Len : op2Len;

	for (int i = 0; i < MAX + 1; i++)
	{
		if (op1Len <= i && op2Len <= i)
			break;
		int op1 = (op1Len - i) > 0 ? opnd1[op1Len - (i+1)] : 0;
		int op2 = (op2Len - i) > 0 ? opnd2[op2Len - (i+1)] : 0;
		carry[strPos-(i+1)] = (op1 + op2 + carry[strPos - i]) / 10;
		result[strPos - (i+1)] = ((op1 + op2 + carry[strPos - i]) % 10) + '0';
	}

	if (carry[0])
		cout << 1;

	for (int i = 0; result[i]; i++)
		cout << result[i];

	return 0;
}