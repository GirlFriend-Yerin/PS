#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll res; cin >> res;
	ll cnt = 10;

	while (cnt < 1e10) {
		if (res % cnt >= 5)
			res += cnt * 10;
		cnt *= 10;
	}
	
	cout << res;

	return 0;
}