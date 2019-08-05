#include <iostream>

using namespace std;

const int EMAX = 16;
const int SMAX = 29;
const int MMAX = 20;

int main()
{
	int e, s, m;
	int res = 1;

	cin >> e >> s >> m;

	for (int cE = 1, sE = 1, mE = 1; res < 9280; res++, cE++, sE++, mE++)
	{
		cE = cE == EMAX ? 1 : cE;
		sE = sE == SMAX ? 1 : sE;
		mE = mE == MMAX ? 1 : mE;

		if (cE == e && sE == s && mE == m)
		{
			cout << res;
			break;
		}
	}

	return 0;
}