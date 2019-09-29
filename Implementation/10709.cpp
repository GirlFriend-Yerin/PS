#include <iostream>

using namespace std;

const int MAX = 100;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c; cin >> r >> c;
	char board[MAX][MAX + 1] = {};

	for (int i = 0; i < r; i++) cin >> board[i];

	for (int i = 0; i < r; i++) {
		bool trigger = false;
		int cnt = -1;
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'c') {
				cnt = 0;
				trigger = true;
			}	
			cout << cnt << ' ';
			cnt += trigger;
		}
		cout << '\n';
	}
	

	return 0;
}