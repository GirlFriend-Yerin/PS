#include <iostream>

using namespace std;

int main()
{
	int r, b;

	cin >> r >> b;

	int maxLength = sqrt(r + b);

	for (int x = 3; x < maxLength +1 ; x++)
	{
		int y = (r + b) / x;

		if ((x * y) == (r + b))
		{
			if ( (x + y -1) * 2 -2 == r && (x-2) * (y-2) == b )
			{
				if (x > y)
					cout << x << " " << y;
				else
					cout << y << " " << x;
				break;
			}
			else if ( (x + y - 1) * 2 -2 == b && (x-2) * (y-2) == r)
			{
				if (x > y)
					cout << x << " " << y;
				else
					cout << y << " " << x;
				break;
			}
		}
	}

	// r = 2x + 2y - 4
	// b = (x-2)(y-2) = xy -2y -2x +4
	// r + b = xy = xy + 2x + 2y - 4 + xy - 2y - x + 4

	return 0;
}