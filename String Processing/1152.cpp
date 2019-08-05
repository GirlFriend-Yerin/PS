/*
	2019 01 05
	1152 단어의 개수
	문자열 처리

	- 성공 - 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence;
	bool firstSpace = false;
	bool lastSpace = false;
	int count = 0;

	getline(cin, sentence);

	if (sentence[0] == ' ')
		firstSpace = true;
	if (sentence[sentence.length() - 1] == ' ')
		lastSpace = true;

	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == ' ')
			count++;
	}

	cout << count + 1 - firstSpace - lastSpace;

	return 0;
}