/*
	2019 01 08
	1107 ������
	Brute force

	- ���� -
*/
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

bool ableButton[10];
int digits[6];
int digitsLength;
int myMin;
int target;

void func(int pos, int numbers[6], int caseType)
{
	if (pos == digitsLength + caseType)
	{
		int zeroCount = 0;
		for (int zPos = pos - zeroCount - 1; zPos > 0 && numbers[zPos] == 0; zPos--) zeroCount++; // ������ 0 �� ���

		int sum = 0;
		for (int i = pos - 1; i >= 0; i--) // �� ���
		{
			sum *= 10;
			sum += numbers[i];
		}

		int count = pos + abs(sum - target) - zeroCount; //�� ���� ���

		//cout << sum << " : " << count << " , " << zeroCount << endl;// For debug

		if (myMin > count)
			myMin = count;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (ableButton[i] == false) // ���峭 ���� Ž������ ����
				continue;

			numbers[pos] = i;
			func(pos + 1, numbers, caseType);
		}
	}
}

int main()
{
	memset(ableButton, true, sizeof(ableButton)); // �迭 �ʱ�ȭ
	int out;

	cin >> target >> out;
	digitsLength = target == 0 || target == 1 ? 1 : log10(target) + 1;

	for (int i = 0; i < out; i++) // ���峭 ��ư �ľ�
	{
		int number;
		cin >> number;
		ableButton[number] = false;
	}

	int number = target;
	for (int i = 0; i < digitsLength; i++) // ���� �ڸ� �и�
	{
		digits[digitsLength - i - 1] = number % 10;
		number /= 10;
	}

	int numbers[6];
	fill_n(numbers, 6, 0);

	myMin = abs(target - 100); // ��ǥ ä�� - ���� ä�� �� �ּҰ����� ����

	if (ableButton[1] && digitsLength < 6) // 10�� �̸��� ��� ���ڸ��� �� �÷��� �˻�
		func(0, numbers, 1);

	if ((ableButton[0] == false && out == 9) || out < 10) // 0�� ������ 9���� ���峪�ų�, ���� ���峭 ���
	{
		func(0, numbers, 0);
		if (digitsLength > 1)
			func(0, numbers, -1);
	}

	cout << myMin;

	return 0;
}