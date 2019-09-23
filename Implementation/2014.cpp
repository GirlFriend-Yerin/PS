#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int candy, n; cin >> candy >> n;

	int won = pow(10, n);
	double rounded = (candy / double(won)) - (candy / won);
	int cal = (candy / won) + (rounded >= 0.5);

	cout << cal * won;
	return 0;
}