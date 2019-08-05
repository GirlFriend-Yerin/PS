#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200000;

struct Ball {
	int color;
	int size;

	Ball() {};
};

struct ColSum {
	int cur;
	int acc;

	ColSum() {}
	ColSum(int cur, int acc) : cur(cur), acc(acc) {}
};

vector<vector<ColSum>> trigger(MAX + 1);
vector<int> colors;

bool cmp(ColSum& cs1, ColSum& cs2) {
	return cs1.cur < cs2.cur;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<Ball> balls(n);
	bool colorChecker[MAX + 1] = {};

	for (int i = 0; i < n; i++) {
		cin >> balls[i].color >> balls[i].size;
		trigger[balls[i].color].push_back(ColSum(balls[i].size, balls[i].size));
		colorChecker[balls[i].color] = true;
	}

	for (int i = 1; i < MAX + 1; i++)
		if (colorChecker[i])
			colors.push_back(i);

	for (int i = 0; i < colors.size(); i++) {
		sort(trigger[colors[i]].begin(), trigger[colors[i]].end(), cmp);

		for (int j = 1; j < trigger[colors[i]].size(); j++) {
			trigger[colors[i]][j].acc += trigger[colors[i]][j - 1].acc;
		}
	}

	for (int i = 0; i < n; i++) {

		int sum = 0;

		for (int j = 0; j < colors.size(); j++) {
			if (balls[i].color != colors[j])
			{
				int left = 0, right = trigger[colors[j]].size() -1 ;

				while (left < right)
				{
					int mid = (left + right) / 2;

					if (trigger[colors[j]][mid].cur < balls[i].size)
						left = mid + 1;
					else
						right = mid - 1;
				}

				if (right >= 0) {
					sum += trigger[colors[j]][right].acc;
					if (trigger[colors[j]][right].cur >= balls[i].size)
						sum -= trigger[colors[j]][right].cur;
				}
			}
		}
		cout << sum << '\n';
	}

	return 0;
}