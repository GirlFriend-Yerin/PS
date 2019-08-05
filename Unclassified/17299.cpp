#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int location[MAX + 1];
int val[MAX + 1];

int vecCnt = 1;
vector<int> cnt(MAX + 1);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
		if (!location[val[i]])
			location[val[i]] = vecCnt++;
		
		cnt[location[val[i]]]++;
	}

	for (int i = 0; i < n; i++) {
		int res = -1;
		for (int j = i + 1; j < n; j++) {
			if (cnt[location[val[i]]] < cnt[location[val[j]]]) {
				res = val[j];
				break;
			}
		}
		cout << res << ' ';
	}

	return 0;
}