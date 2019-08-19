#include <iostream>

using namespace std;

const int MAX = 10;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int rooms[MAX] = {};
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		char input; cin >> input;

		if (input == 'L') {
			int pos = 0;
			while (pos < MAX && rooms[pos]) pos++;
			if (pos < MAX)
				rooms[pos] = 1;
		}
		else if (input == 'R') {
			int pos = MAX - 1;
			while (pos >= 0 && rooms[pos]) pos--;
			if (pos >= 0)
				rooms[pos] = 1;
		}
		else {
			rooms[input - '0'] = 0;
		}
	}

	for (int i = 0; i < MAX; i++)
		cout << rooms[i];

	return 0;
}