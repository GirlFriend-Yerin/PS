#include <iostream>
#include <vector>

using namespace std;

void rotation(vector<vector<int>>& vec, int n) {
	for (int i = 0; i < n / 2; i++)
		for (int j = i; j < n- 1 - i; j++)
		{
			int Top = vec[i][j];
			vec[i][j] = vec[n - 1 - j][i];
			vec[n - 1 - j][i] = vec[n - 1 - i][n - 1 - j];
			vec[n - 1 - i][n - 1 - j] = vec[j][n - 1 - i]; 
			vec[j][n - 1 - i] = Top;
		}
}

bool validate(const vector<vector<int>>& board, int n) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (board[i][j] == 0 || board[i][j] == 2) return false;

	return true;
}

bool check(vector<vector<int>>& key, vector<vector<int>> board, int sX, int sY, int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int posX = sX + i;
			int posY = sY + j;
			if (0 <= posX && posX < n && 0 <= posY && posY < n)
				board[posX][posY] = board[posX][posY] + key[i][j];
		}
	}

	return validate(board, n);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	int m = key.size();
	int n = lock.size();

	for (int i = 0; i < 4; i++) {
		
		for (int sX = -m ; sX < n; sX++)
			for (int sY = -m ; sY < n; sY++)
				if (check(key, lock, sX, sY, m, n)) return true;
			
		rotation(key, m);
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int n, m; cin >> m >> n;

	vector<vector<int>> key(m, vector<int>(m)); 
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> key[i][j];

	vector<vector<int>> lock(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> lock[i][j];

	cout << (solution(key, lock) ? "True" : "False") ;

	return 0;
}