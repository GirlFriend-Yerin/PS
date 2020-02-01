#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 105;
const int WORD_MAX = 85;

struct Point {
	char x, y;
	Point() {};
	Point(char x, char y) : x(x), y(y) {};
};

int n, m, k;

int bfs(const char table[MAX][MAX + 1], const char word[MAX + 1])
{
	queue<Point> q;
	queue<Point> nQ;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (table[i][j] == word[0]) 
				q.push(Point(i, j));

	for (int phase = 1; word[phase] ; phase++)
	{
		while (!q.empty()) {
			Point now = q.front(); q.pop();

			for (char i = 1; i <= k; i++) {

				// top
				if (now.x - i >= 0 && word[phase] == table[now.x - i][now.y])
					nQ.push(Point(now.x - i, now.y));

				// bottom
				if (now.x + i < n && word[phase] == table[now.x + i][now.y])
					nQ.push(Point(now.x + i, now.y));

				// left
				if (now.y - i >= 0 && word[phase] == table[now.x][now.y - i])
					nQ.push(Point(now.x, now.y - i));

				// right
				if (now.y + i < m && word[phase] == table[now.x][now.y + i])
					nQ.push(Point(now.x, now.y + i));
			}
		}

		while (!nQ.empty()) {
			q.push(nQ.front());
			nQ.pop();
		}
	}

	return q.size();
}

int dfs(const char table[MAX][MAX + 1], const char word[MAX + 1], int pos, int x, int y)
{
	if (!word[pos])
		return 1;

	int res = 0;

	for (char i = 1; i <= k; i++) {

		// top
		if (x - i >= 0 && word[pos] == table[x - i][y])
			res += dfs(table, word, pos + 1, x - i, y);

		// bottom
		if (x + i < n && word[pos] == table[x + i][y])
			res += dfs(table, word, pos + 1, x + i, y);

		// left
		if (y - i >= 0 && word[pos] == table[x][y - i])
			res += dfs(table, word, pos + 1, x, y - i);

		// right
		if (y + i < m && word[pos] == table[x][y + i])
			res += dfs(table, word, pos + 1, x, y + i);
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	char table[MAX + 1][MAX + 1] = {};
	char word[WORD_MAX + 1] = {};

	for (int i = 0; i < n; i++)
		cin >> table[i];
	cin >> word;

	//cout << bfs(table, word);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (table[i][j] == word[0])
				res += dfs(table, word, 1, i, j);

	cout << res;

	return 0;
}