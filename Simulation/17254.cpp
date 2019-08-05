#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Typing {
	int keyboard;
	int time;
	char key;

	Typing() {};
	Typing(int keyboard, int time, char key) : keyboard(keyboard), time(time), key(key) {}
};

vector<Typing> reserve;

bool cmp(Typing& t1, Typing& t2) {
	if (t1.time < t2.time)
		return true;
	else if (t1.time == t2.time) {
		if (t1.keyboard < t2.keyboard)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	reserve.resize(m);

	for (int i = 0; i < m; i++) 
		cin >> reserve[i].keyboard >> reserve[i].time >> reserve[i].key;
	
	sort(reserve.begin(), reserve.end(), cmp);

	for (int i = 0; i < m ; i++)
		cout << reserve[i].key;

	return 0;
}