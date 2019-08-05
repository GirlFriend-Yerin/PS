#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country {
	int num;
	int gold;
	int silver;
	int bronze;
	int rank;
};

bool cmp(Country& c1, Country& c2) {
	if (c1.gold != c2.gold)
		return c1.gold > c2.gold;
	if (c1.silver != c2.silver)
		return c1.silver > c2.silver;
	return c1.bronze > c2.bronze;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, tar; cin >> n >> tar;

	vector<Country> data(n);

	for (int i = 0; i < n; i++)
		cin >> data[i].num >> data[i].gold >> data[i].silver >> data[i].bronze;

	sort(data.begin(), data.end(), cmp);

	data[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (data[i].gold == data[i - 1].gold && data[i].silver == data[i - 1].silver && data[i].bronze == data[i - 1].bronze)
			data[i].rank = data[i - 1].rank;
		else
			data[i].rank = i + 1;
	}

	for (int i = 0; i < n; i++) {
		if (data[i].num == tar) {
			cout << data[i].rank;
			break;
		}
	}

	return 0;
}