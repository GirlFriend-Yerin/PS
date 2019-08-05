/*
	2019 03 02
	16944 강력한 비밀번호
	문자열 처리

	- 성공 -
*/
#include <iostream>

using namespace std;

const short MAX = 100;
const short WORDS_MAX = 12;

bool isSpecial(char c)
{
	char words[WORDS_MAX] = { '!', '@','#','$','%','^','&','*','(',')', '-', '+' };
	for (int i = 0; i < WORDS_MAX; i++)
		if (c == words[i])
			return true;

	return false;
}

int main()
{
	bool trigger[4] = {};
	char input[MAX] = {};
	int len, need, needTrigCount = 0;

	cin >> len >> input;

	need = 6 - len;

	for (int i = 0; i < len; i++)
	{
		if ('0' <= input[i] && input[i] <= '9')
			trigger[0] = true;
		else if ('a' <= input[i] && input[i] <= 'z')
			trigger[1] = true;
		else if ('A' <= input[i] && input[i] <= 'Z')
			trigger[2] = true;
		else if (isSpecial(input[i]))
			trigger[3] = true;
	}

	for (int i = 0; i < 4; i++)
		if (!trigger[i])
			needTrigCount++;

	cout << (need < needTrigCount ? needTrigCount : need);

	return 0;
}