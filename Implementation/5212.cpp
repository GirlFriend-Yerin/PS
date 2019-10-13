#include <iostream>

using namespace std;

const short MAX = 10;

int posX[] = { 1, 0, -1, 0 };
int posY[] = { 0, 1, 0 , -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	char now[MAX + 2][MAX + 3] = {} , later[MAX + 2][MAX + 3] = {};
	for (int i = 0; i < MAX + 2; i++) for (int j = 0; j < MAX + 3; j++) now[i][j] = later[i][j]= '.';

	for (int i = 0; i < n; i++) {
		char input[MAX + 1]; cin >> input;
		for (int x = 1; x <= m; x++)
			now[i + 1][x] = input[x - 1];
	}
		
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (now[i][j] == '.') continue;
			else {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextX = i + posX[k];
					int nextY = j + posY[k];
					if (0 <= nextX && nextX <= n+1 && 0 <= nextY && nextY <= m+1)
						cnt += now[nextX][nextY] == '.';
				}
				later[i][j] = cnt >= 3 ? '.' : 'X';
			}
		}
	}

	int startX = 1, endX = m, startY = 0, endY = n;
	while (startX <= m) {
		bool next = true;
		for (int i = 1; i <= n; i++)
			next &= later[i][startX] == '.';
		if (next) startX++;
		else
			break;
	}

	while (endX > startX) {
		bool next = true;
		for (int i = 1; i <= n; i++)
			next &= later[i][endX] == '.';
		if (next) endX--;
		else
			break;
	}

	while (startY <= n) {
		bool next = true;
		for (int i = 1; i <= m; i++)
			next &= later[startY][i] == '.';
		if (next) startY++;
		else
			break;
	}

	while (endY > startY) {
		bool next = true;
		for (int i = 1; i <= m; i++)
			next &= later[endY][i] == '.';
		if (next) endY--;
		else
			break;
	}

	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++)
			cout << later[i][j];
		cout << '\n';
	}

	return 0;
}