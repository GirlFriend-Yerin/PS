#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--)
	{
		int h, w, n; cin >> h >> w >> n;
		printf("%d%02d\n", (n - 1) % h + 1, (n - 1) / h + 1);
	}

	return 0;
}