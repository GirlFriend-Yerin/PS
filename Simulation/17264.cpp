#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> win;
vector<string> lose;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p; cin >> n >> p;
	int w, l, g; cin >> w >> l >> g;

	for (int i = 0; i < p; i++) {
		string name;
		char ch;

		cin >> name >> ch;

		if (ch == 'W')
			win.push_back(name);
		else
			lose.push_back(name);
	}

	int score = 0;

	for (int i = 0; i < n; i++) {
		string name; cin >> name;

		bool foundWin = false;
		for (int i =0; i < win.size(); i++)
			if (win[i] == name)
			{
				foundWin = true;
				break;
			}
		if (foundWin)
			score += w;
		else {
			if (score < l)
				score = 0;
			else
				score -= l;
		}

		if (score >= g)
			break;
	}

	if (score < g)
		cout << "I AM IRONMAN!!";
	else
		cout << "I AM NOT IRONMAN!!";

	return 0;
}