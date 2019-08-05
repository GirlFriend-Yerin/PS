#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int answer = 5000;
	int type;

	while (cin >> type)
	{
		switch (type)
		{
		case 1:
			answer -= 500;
			break;
		case 2:
			answer -= 800;
			break;
		case 3:
			answer -= 1000;
		default:
			break;
		}
	}
	
	cout << answer;

	return 0;
}