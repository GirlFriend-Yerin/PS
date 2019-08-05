#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int board[100001];
	int sumBoard[100001];
	int n, tcc;

	scanf("%d %d", &n, &tcc);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &board[i]);
		sumBoard[i] = sumBoard[i - 1] + board[i];
	}

	for (int i = 0; i < tcc; i++)
	{
		int start, des;

		scanf("%d %d", &start, &des);
		printf("%d\n", sumBoard[des] - sumBoard[start - 1]);
	}

	return 0;
}