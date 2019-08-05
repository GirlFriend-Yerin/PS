#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <math.h>

using namespace std;

const double pi = acos(-1.0);

int main()
{
	double r; scanf("%lf", &r);

	printf("%.6f\n%.6f", pi * r * r, 2 * r * r);

	return 0;
}