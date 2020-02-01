#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int NMAX = 14;
const int KMAX = 10;
const int TURN_MAX = 1000;
const int posX[] = { 0, 0, -1, 1 };
const int posY[] = { 1, -1, 0, 0 };

struct Node {
	int x, y, d;

	Node() {}
	Node(int x, int y, int d) : x(x), y(y), d(d) {};

	void reverse() { d ^= 1; }
};

bool isOver(deque<int> board[NMAX][NMAX], vector<Node>& nodes) {
	for (Node& node : nodes)
		if (board[node.x][node.y].size() > 3)
			return true;
	return false;
}

int findIdx(deque<int>& dq, int key) {
	for (int i = 0; i < dq.size(); i++)
		if (dq[i] == key) return i;
	return -1;
}

vector<int> moveNRemove(deque<int>& to, deque<int>& des, int idx, int removeCount, bool reverse) {
	vector<int> buffer; for (int i = idx; i < to.size(); i++) buffer.push_back(to[i]);
	while (removeCount--) to.pop_back();
	if (reverse) for (int i = buffer.size(); i; i--) des.push_back(buffer[i - 1]);
	else for (int node : buffer) des.push_back(node);

	return buffer;
}

void update(vector<Node>& nodes, vector<int>& targets, int nextX, int nextY)
{
	for (int target : targets) {
		nodes[target].x = nextX;
		nodes[target].y = nextY;
	}
}

int game(const int table[NMAX][NMAX], deque<int> board[NMAX][NMAX], vector<Node>& nodes, const int n, const int k)
{
	int turn = 0;
	bool gameEnd = false;

	for (; turn <= TURN_MAX && !gameEnd; turn++) {
		for (int i = 0; i < k; i++) {
			int curX = nodes[i].x;
			int curY = nodes[i].y;
			int nextX = curX + posX[nodes[i].d];
			int nextY = curY + posY[nodes[i].d];

			switch (table[nextX][nextY])
			{
				// Èò»ö
			case 0:
			{
				int idx = findIdx(board[curX][curY], i);

				vector<int> targets = moveNRemove(board[curX][curY], board[nextX][nextY], idx, board[curX][curY].size() - idx, false);
				update(nodes, targets, nextX, nextY);
			}
			break;
			case 1:
			{
				int idx = findIdx(board[curX][curY], i);
				vector<int> targets = moveNRemove(board[curX][curY], board[nextX][nextY], idx, board[curX][curY].size() - idx, true);
				update(nodes, targets, nextX, nextY);
			}
			break;
			case 2:
			{
				nodes[i].reverse();
				nextX = curX + posX[nodes[i].d];
				nextY = curY + posY[nodes[i].d];

				if (table[nextX][nextY] == 2) break;

				int idx = findIdx(board[curX][curY], i);

				vector<int> targets = moveNRemove(board[curX][curY], board[nextX][nextY], idx, board[curX][curY].size() - idx, table[nextX][nextY]);
				update(nodes, targets, nextX, nextY);
			}
			break;
			}

			if (isOver(board, nodes)) {
				gameEnd = true;
				break;
			}
		}
	}

	return gameEnd ? turn : -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	int table[NMAX][NMAX] = {};
	deque<int> board[NMAX][NMAX];
	vector<Node> nodes(k);

	// boundary
	for (int i = 0; i < NMAX; i++) table[i][0] = table[0][i] = table[i][n + 1] = table[n + 1][i] = 2;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> table[i][j];

	for (int i = 0; i < k; i++)
	{
		cin >> nodes[i].x >> nodes[i].y >> nodes[i].d;
		board[nodes[i].x][nodes[i].y].push_front(i);

		--nodes[i].d;
	}

	cout << game(table, board, nodes, n, k);

	return 0;
}