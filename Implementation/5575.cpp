#include <iostream>

using namespace std;

struct Time {
	int h, m, s;
};

void printWorkingTime(const Time& t1, const Time& t2) {
	int h = t2.h - t1.h;
	int m = t2.m - t1.m;
	int s = t2.s - t1.s;

	if (s < 0) {
		m--;
		s += 60;
	}
	if (m < 0) {
		h--;
		m += 60;
	}

	cout << h << ' ' << m << ' ' << s << '\n';
}


int main()
{
	Time times[3][2]; 

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			cin >> times[i][j].h >> times[i][j].m >> times[i][j].s;

	for (int i = 0; i < 3; i++)
		printWorkingTime(times[i][0], times[i][1]);

	return 0;
}