#include <iostream>

using namespace std;

const int MAX = 1000;

int board[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];

const int posX[] = { 1, 0 };
const int posY[] = { 0, 1 };

const int _max(const int a, const int b) { return a ^ ((a^b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w, n; cin >> h >> w >> n;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];

	dp[0][0] = n - 1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dp[i][j + 1] += board[i][j] % 2 ? (dp[i][j] + 1) / 2 : dp[i][j] - ((dp[i][j] + 1) / 2);
			dp[i + 1][j] += board[i][j] % 2 ? dp[i][j] - ((dp[i][j] + 1) / 2) : (dp[i][j] + 1) / 2;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			board[i][j] += dp[i][j];
		}
	}

	int resX = 0, resY = 0;
	while (0 <= resX && resX < h && 0 <= resY && resY < w) {
		int move = board[resX][resY] & 1;
		resX += posX[move]; resY += posY[move];
	}

	cout << resX + 1 << ' ' << resY + 1;

	return 0;
}