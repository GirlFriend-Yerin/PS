#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int yes = 0;
	for (int i = 0; i < n; i++)
	{
		int val; cin >> val;
		yes += val;
	}

	cout << (n - yes < yes ? "Junhee is not cute!" : "Junhee is cute!");

	return 0;
}