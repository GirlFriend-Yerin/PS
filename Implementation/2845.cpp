/*
	2019 07 24
	2845 - ��Ƽ�� ������ ���ڤ�

	Pass
*/
#include <iostream>

using namespace std;

int main()
{
	int x, y; cin >> x >> y;

	int tar = x * y;

	for (int i = 0; i < 5; i++) {
		int val; cin >> val;

		cout << val - tar << ' ';
	}

	return 0;
}