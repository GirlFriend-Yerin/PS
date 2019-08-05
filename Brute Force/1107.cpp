/*
	2019 01 08
	1107 리모컨
	Brute force

	- 성공 -
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
		for (int zPos = pos - zeroCount - 1; zPos > 0 && numbers[zPos] == 0; zPos--) zeroCount++; // 시작이 0 인 경우

		int sum = 0;
		for (int i = pos - 1; i >= 0; i--) // 값 계산
		{
			sum *= 10;
			sum += numbers[i];
		}

		int count = pos + abs(sum - target) - zeroCount; //값 차이 계산

		//cout << sum << " : " << count << " , " << zeroCount << endl;// For debug

		if (myMin > count)
			myMin = count;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (ableButton[i] == false) // 고장난 경우는 탐색하지 않음
				continue;

			numbers[pos] = i;
			func(pos + 1, numbers, caseType);
		}
	}
}

int main()
{
	memset(ableButton, true, sizeof(ableButton)); // 배열 초기화
	int out;

	cin >> target >> out;
	digitsLength = target == 0 || target == 1 ? 1 : log10(target) + 1;

	for (int i = 0; i < out; i++) // 고장난 버튼 파악
	{
		int number;
		cin >> number;
		ableButton[number] = false;
	}

	int number = target;
	for (int i = 0; i < digitsLength; i++) // 숫자 자리 분리
	{
		digits[digitsLength - i - 1] = number % 10;
		number /= 10;
	}

	int numbers[6];
	fill_n(numbers, 6, 0);

	myMin = abs(target - 100); // 목표 채널 - 현재 채널 을 최소값으로 설정

	if (ableButton[1] && digitsLength < 6) // 10만 미만의 경우 한자리를 더 늘려서 검색
		func(0, numbers, 1);

	if ((ableButton[0] == false && out == 9) || out < 10) // 0을 포함해 9개가 고장나거나, 전부 고장난 경우
	{
		func(0, numbers, 0);
		if (digitsLength > 1)
			func(0, numbers, -1);
	}

	cout << myMin;

	return 0;
}