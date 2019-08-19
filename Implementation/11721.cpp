/*
	2019-08-07
	열 개씩 끊어 출력하기
*/
#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	char input[MAX + 1] = {}; cin >> input;

	for (int pos = 0; input[pos] != '\0'; pos++) {
		cout << input[pos];
		if ((pos+1) % 10 == 0)
			cout << '\n';
	}

	return 0;
}