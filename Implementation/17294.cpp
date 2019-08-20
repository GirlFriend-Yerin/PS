#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	int res = 1;
	for (int i = 0; i < n; i++)
	{
		float temp; cin >> temp;
		res += (int)temp;
	}

	cout << res;

	return 0;
}