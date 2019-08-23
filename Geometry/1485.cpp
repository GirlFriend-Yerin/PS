#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		Point points[4];
		vector<ll> side;

		for (int i = 0; i < 4; i++)
			cin >> points[i].x >> points[i].y;

		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 4; j++) {
				ll xDif = points[i].x - points[j].x;
				ll yDif = points[i].y - points[j].y;

				side.push_back((xDif * xDif) + (yDif * yDif));
			}

		sort(side.begin(), side.end());

		bool isAble = (side[0] == side[1] && side[1] == side[2] && side[2] == side[3]) && (side[4] == side[5]);

		cout << (int)isAble << '\n';
	}

	return 0;
}