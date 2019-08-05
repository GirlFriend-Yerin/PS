#include <iostream>

using namespace std;

const short MAX = 1000;

int board[MAX][MAX];
int dp[MAX][MAX];

const int posX[] = { -1, 0, -1 };
const int posY[] = { 0, -1, -1 };

int max(const int& a, const int& b, const int& c) {
	if (a < b && c < b)
		return b;
	else if (a < c && b < c)
		return c;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	dp[0][0] = board[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i || j) {
				int sum[3] = {};
				for (int k = 0; k < 3; k++) {
					int beforeX = i + posX[k];
					int beforeY = j + posY[k];
					if (0 <= beforeX && beforeX < n && 0 <= beforeY && beforeY < m)
						sum[k] = board[i][j] + dp[beforeX][beforeY];
				}
				dp[i][j] = max(sum[0], sum[1], sum[2]);
			}
		}
	}

	cout << dp[n - 1][m - 1];

	return 0;
}