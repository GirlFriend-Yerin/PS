/*
	2019 01 05
	2869 - �����̴� �ö󰡰�ʹ�
	MatheMatics

	- ���� -
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, v;

	scanf("%d %d %d", &a, &b, &v);

	int diff = v - a;
	int day = a - b;

	if (diff <= 0)
		printf("%d", 1);
	else
	{
		if (diff % day)
			printf("%d", diff / day + 2);
		else
			printf("%d", diff / day + 1);
	}


	return 0;
}