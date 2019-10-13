#include <iostream>

using namespace std;

const int MAX = 100;
const int ALPHA_MAX = 26;

bool isGroup(char str[MAX + 1]) {
	int visited[ALPHA_MAX] = {};

	visited[str[0] - 'a']++;
	for (int i = 1; str[i]; i++) {
		if (str[i - 1] != str[i])
			visited[str[i] - 'a']++;
	}

	for (int i = 0; i < ALPHA_MAX; i++)
		if (visited[i] > 1)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		char input[MAX + 1]; cin >> input;
		res += (isGroup(input));
	}

	cout << res;

	return 0;
}