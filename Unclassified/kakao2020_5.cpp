#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const short MAX = 101;

bool cmp(const vector<int>& item1, const vector<int>& item2) {
	return item1[0] != item2[0] ? item1[0] < item2[0] : item1[1] < item2[2];
}

bool checkBoUnderGidung(bool gidung[MAX][MAX], int n, int x, int y) {
	return (x >= 0 && gidung[x][y - 1]) || (x + 1 <= n && gidung[x + 1][y - 1]);
}

bool checkBoExsit(bool gidung[MAX][MAX], bool bo[MAX][MAX], int n, int x, int y) {
	if (gidung[x][y - 1] || gidung[x + 1][y - 1]) // 왼쪽 or 오른쪽에 기둥
		return true;
	else {
		if ((x && bo[x - 1][y]) && bo[x + 1][y]) // 양쪽에 보가 존재
			return true;
	}
	return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	bool gidung[MAX][MAX ] = {};
	bool bo[MAX][MAX] = {};

	for (vector<int> order : build_frame) {
		int x = order[0], y = order[1], a = order[2], b = order[3];

		if (b) {
			if (a) { // 보
				if (y && x + 1 <= n)
				{
					if (gidung[x][y - 1] || gidung[x + 1][y - 1]) // 왼쪽 or 오른쪽에 기둥
						bo[x][y] = true;
					else {
						if ((x && bo[x - 1][y]) && bo[x + 1][y]) // 양쪽에 보가 존재
							bo[x][y] = true;
					}
				}
			}
			else { // 기둥
				if (y) {
					if (gidung[x][y - 1]) // 밑에 기둥이 있을 때
						gidung[x][y] = true;
					else if (x && bo[x - 1][y])
						gidung[x][y] = true;
				}
				else
					gidung[x][y] = true;
			}
		}
		else {
			if (a) { // 보
				if ((x > 0 && bo[x - 1][y] && (gidung[x - 1][y - 1] || gidung[x][y-1])) && (x < n && bo[x + 1][y] && gidung[x + 1][y - 1]) ) bo[x][y] = false;
			}
			else { // 기둥
				if (!gidung[x][y + 1]) gidung[x][y] = false;
				else {
					gidung[x][y] = false;
					bool left = !x || checkBoExsit(gidung, bo, n, x - 1, y + 1);
					bool right = x == n || checkBoExsit(gidung, bo,n , x, y + 1);
					if (!(left && right)) 
						gidung[x][y] = true;
				}
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (gidung[i][j]) {
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				temp.push_back(0);
				answer.push_back(temp);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bo[i][j]) {
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				temp.push_back(1);
				answer.push_back(temp);
			}
		}
	}

	sort(answer.begin(), answer.end(), cmp);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, b; cin >> n >> b;
	vector<vector<int>> input(b, vector<int>(4));

	for (int i = 0; i < b; i++)
		for (int j = 0; j < 4; j++)
			cin >> input[i][j];
	
	vector<vector<int>> sol = solution(n, input);

	for (int i = 0; i < sol.size(); i++)
		cout << sol[i][0] << sol[i][1] << sol[i][2] << '\n';

	return 0;
}