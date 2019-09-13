#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		char input[MAX + 1] = {}; cin >> input;

		stack<char> stk;
		stk.push(input[0]);

		for (int j = 1; input[j]; j++) {
			if (stk.empty() || stk.top() != input[j])
				stk.push(input[j]);
			else
				stk.pop();
		}

		res += stk.empty();
	}

	cout << res;

	return 0;
}