#include <iostream>

using namespace std;

void max(int& a, int& b, int& c) {

	if (b < a && c < a)
		swap(c, a);
	else if (a < b && c < b)
		swap(c, b);
}

int main()
{
	int a, b, c; cin >> a >> b >> c;

	while (a || b || c)
	{
		max(a, b, c);

		if ((a * a + b * b) != (c * c) || !a || !b || !c)
			cout << "wrong\n";
		else
			cout << "right\n";

		cin >> a >> b >> c;
	}
	return 0;
}