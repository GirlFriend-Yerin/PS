#include <iostream>
#include <string>
#include <vector>

using namespace std;

const short MAX = 16;
bool board[MAX][MAX];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tag = 1 << (n - j - 1);
			if (arr1[i] >= tag) {
				board[i][j] = true;
				arr1[i] -= tag;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int tag = 1 << (n - i - 1);
		for (int j = 0; j < n; j++) {
			if (arr2[j] >= tag) {
				board[j][i] = true;
				arr2[j] -= tag;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		string str;
		for (int j = 0; j < n; j++)
			str.push_back(board[i][j] ? '#' : ' ');
		answer.push_back(str);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> arr1(n);
	vector<int> arr2(n);

	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	vector<string> answer = solution(n, arr1, arr2);

	for (int i = 0; i < n; i++)
		cout << answer[i] << '\n';

	return 0;
}