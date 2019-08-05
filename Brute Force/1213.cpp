/*
	2019 01 10
	1213 �Ӹ���� �����
	Brute force

	- ���� -
*/
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int alpha[26];

string func(int length)
{
	char res[51];
	memset(res, 0, sizeof(res));

	if (length % 2)
	{
		int min;
		for (min = 0; alpha[min] % 2 == 0; min++);

		res[length / 2] = char(min + 'A'); // ��� ���� ä���
		alpha[min]--;
	}

	int min = 0;
	for (int i = 0; i < length / 2; i++)
	{
		for (; alpha[min] == 0; min++); // ���� �ּ� �� �˻�

		res[i] = res[length - i - 1] = min + 'A';
		alpha[min] -= 2;
	}
		
	return string(res);
}

int main()
{
	string input;
	int strLen;

	cin >> input;
	strLen = input.length();

	for (int i = 0; i < strLen; i++)
		alpha[input[i] - 'A']++;

	if (strLen % 2) // ���̰� Ȧ���� ���
	{
		int count = 0;

		for (int i = 0; i < 26; i++)
			if (alpha[i] % 2)
				count++;

		if (count > 1) // ������ Ȧ���� ���ĺ��� 1�� �̻��̸� ���� �Ұ�
			cout << "I'm Sorry Hansoo";
		else
			cout << func(strLen);
	}
	else // ���̰� ¦���� ���
	{
		int count = 0;

		for (int i = 0; i < 26; i++)
			if (alpha[i] % 2)
				count++;

		if (count > 0) // ������ Ȧ���� ���ĺ��� �����ϸ� ���� �Ұ�
			cout << "I'm Sorry Hansoo";
		else
			cout << func(strLen);
	}

	return 0;
}