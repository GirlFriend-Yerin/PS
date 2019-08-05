#include <iostream>

using namespace std;

const int MAX = 10004;

char res[MAX] = {};

int add(char* str1, char* str2) {

	int pStr1 = 0, pStr2 = 0;

	while (str1[pStr1]) pStr1++;
	while (str2[pStr2]) pStr2++;

	int pRes = 0;

	bool carry = false;

	while (pStr1 && pStr2) {
		int stri1 = str1[--pStr1] - '0';
		int stri2 = str2[--pStr2] - '0';

		int sum = (stri1 + stri2 + carry) % 10;
		carry = stri1 + stri2 + carry > 9;

		res[pRes++] = sum + '0';
	}

	while (pStr1) {
		int stri = str1[pStr1--] - '0';

		carry = stri == 9;
		res[pRes++] = (stri + carry) % 10;
	}

	while (pStr2) {
		int stri = str2[pStr2--] - '0';

		carry = stri == 9;
		res[pRes++] = (stri + carry) % 10;
	}

	if (carry)
		res[pRes++] = '1';

	return pRes;
}

// str2 is negative
int sub(char* str1, char* str2) {
	int pStr1 = 0, pStr2 = 0, pRes = 0;

	while (str1[pStr1]) pStr1++;
	while (str2[pStr2]) pStr2++;

	bool carry = false;

	while (pStr1 && pStr2 > 1) {
		int str1i = str1[--pStr1] - '0';
		int str2i = str2[--pStr2] - '0';

		int sum = (10 + (str1i - str2i - carry)) % 10;
		carry = str1i < str2i + carry;

		res[pRes++] = sum + '0';
	}

	bool isMinus = pStr2 > 1 || ((pStr2 - 1) == pStr1) && !carry;

	while (pStr1) {
		int str1i = str1[--pStr1] - '0';
		int sum = (10 + (str1i - carry)) % 10;
		carry = str1i < carry;

		res[pRes++] = sum + '0';
	}

	while (pStr2 > 1) {
		int str2i = str2[--pStr2] - '0';
		int sum = (10 + str2i + carry) % 10;
		carry = str2i == 9;

		res[pRes++] = sum + '0';
	}

	res[pRes++] = isMinus ? '-' : '0';

	return pRes;
}

void printReverse(int pos) {
	bool isMinus = res[pos] == '-';
	pos -= isMinus;

	while (res[pos] == '0' || res[pos] == '\0')
		pos--;

	while (pos >= 0)
		cout << res[pos--];
}

int main()
{
	char input1[MAX] = {}, input2[MAX] = {};

	cin >> input1;
	cin >> input2;

	if (input1[0] != '-' && input2[0] != '-')
		printReverse(add(input1, input2));
	else if (input1[0] == '-')
		printReverse(sub(input2, input1));
	else if (input2[0] == '-')
		printReverse(sub(input2, input1));
	else if (input1[0] == '-' && input2[0] == '-')
	{
		int rPos = add(&input1[1], &input2[1]);
		res[rPos++] = '-';
		printReverse(rPos);
	}

	//printReverse(add(input1, input2));

	return 0;
}