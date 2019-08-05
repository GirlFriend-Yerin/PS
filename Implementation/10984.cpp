#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main()
{
	int t; scanf("%d", &t);

	while (t--) {
		int sumHak = 0;
		double sumScore = 0.0;

		int n; scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int hak; scanf("%d", &hak);
			double score; scanf("%lf", &score);

			sumHak += hak;
			sumScore += hak * score;
		}

		printf("%d %.1f\n", sumHak, sumScore / sumHak);
	}

	return 0;
}