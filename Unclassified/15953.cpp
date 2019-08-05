#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

const int first_person[] = { 0, 1, 3, 6, 10, 15, 21};
const int first_reword[] = { 500, 300 ,200 ,50 , 30 ,10};
const int second_person[] = { 0, 1, 3, 7, 15, 31 };
const int second_reword[] = { 512, 256, 128, 64, 32 };

int main()
{
	int tcc;

	scanf("%d", &tcc);

	while (tcc--)
	{
		int first, second, fnd = -1, snd = -1;
		int sum = 0;

		scanf("%d %d", &first, &second);

		for (int i = 0; i < 6; i++)
		{
			if (first_person[i] < first && first <= first_person[i + 1])
				sum += first_reword[i];

			if (second_person[i] < second && second <= second_person[i + 1])
				sum += second_reword[i];
		}

		printf("%d\n", sum * 10000);
	}
	return 0;
}