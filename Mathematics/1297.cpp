#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int l, a, b; cin >> l >> a >> b;
	double c = sqrt(a* a + b * b);
	int w = a * l / c, h = b * l / c;

	cout << w << ' ' << h;

	return 0;
}
