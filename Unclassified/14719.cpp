#include <iostream>

using namespace std;

const short MAX = 500;

short _max(const short a, const short b) { return a ^ ((a ^ b) & -(a < b)); }
short _min(const short a, const short b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int res = 0;
	int h, w; cin >> h >> w;
	short board[MAX] = {}; for (int i = 0; i < w; i++) cin >> board[i];
	
	short right = 0;
	short rightMax[MAX] = {}; for (int i = w; i >= 0; i--) right = rightMax[i] = _max(right, board[i]);

	int left = board[0];
	for (int i = 1; i < w ; i++) {
		int minValue = _min(rightMax[i], left);
		res += minValue > board[i] ? minValue - board[i] : 0;
		left = _max(left, board[i]);
	}

	cout << res;

	return 0;
}