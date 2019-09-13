#include <iostream>
#include <vector>

using namespace std;

const short MAX = 9;

int n;
char oper[MAX + 1];

bool validation(const vector<int>& vec) {
	for (int i = 0; i < n; i++) {
		if (oper[i] == '<') {
			if (vec[i] > vec[i + 1])
				return false;
		}
		else {
			if (vec[i] < vec[i + 1])
				return false;
		}
	}
	return true;
}

bool dfs(vector<int>& vec,vector<bool>& visited,const int pos,const bool topDown) {

	if (pos == n + 1) 
		return validation(vec);
	
	for (int i = (topDown ? 9 : 0); (topDown ? i >= 0 : i < 10); i += (topDown ? -1 : 1)) {
		if (visited[i]) continue;
		visited[i] = true;
		vec[pos] = i;
		if (dfs(vec, visited, pos + 1, topDown))
			return true;

		visited[i] = false;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> vec(10);
	vector<bool> visited(10);

	for (int i = 0; i < n; i++)
		cin >> oper[i];

	dfs(vec, visited, 0, true);
	for (int i = 0; i < n + 1; i++)
		cout << vec[i] << ' ';
	cout << '\n';

	for (int i = 0; i < 10; i++)
		visited[i] = false;

	dfs(vec, visited, 0, false);
	for (int i = 0; i < n + 1; i++)
		cout << vec[i] << ' ';
	cout << '\n';

	return 0;
}