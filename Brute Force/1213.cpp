/*
	2019 01 10
	1213 팰린드롬 만들기
	Brute force

	- 성공 -
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

		res[length / 2] = char(min + 'A'); // 가운데 글자 채우기
		alpha[min]--;
	}

	int min = 0;
	for (int i = 0; i < length / 2; i++)
	{
		for (; alpha[min] == 0; min++); // 사전 최소 값 검색

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

	if (strLen % 2) // 길이가 홀수인 경우
	{
		int count = 0;

		for (int i = 0; i < 26; i++)
			if (alpha[i] % 2)
				count++;

		if (count > 1) // 갯수가 홀수인 알파벳이 1개 이상이면 생성 불가
			cout << "I'm Sorry Hansoo";
		else
			cout << func(strLen);
	}
	else // 길이가 짝수인 경우
	{
		int count = 0;

		for (int i = 0; i < 26; i++)
			if (alpha[i] % 2)
				count++;

		if (count > 0) // 갯수가 홀수인 알파벳이 존재하면 생성 불가
			cout << "I'm Sorry Hansoo";
		else
			cout << func(strLen);
	}

	return 0;
}