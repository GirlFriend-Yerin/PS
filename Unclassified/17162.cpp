#include <iostream>

using namespace std;

const int QUERY_MAX = 1000000;

struct CustomStack
{
	int data[QUERY_MAX+1];
	int top = 0;

	void push(int val) {
		data[top++] = val;
	}

	void pop() {
		if (top)
			top--;
	}

	int customFunc(int n) {

		int res = 0;
		bool forCheck[QUERY_MAX + 1] = {};
		int checker = n * (n + 1) / 2 ;

		for (int pos = top - res - 1; res < top && checker != 0; pos = top - (++res) - 1)
		{
			int mod = data[pos] % n;
			if (!forCheck[mod]) {
				forCheck[mod] = true;
				checker -= mod + 1;
			}
		}
	
		if (checker == 0)
			return res;
		return -1;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int query, mod;
	CustomStack stack;

	cin >> query >> mod;

	for (int i = 0; i < query; i++)
	{
		int order; cin >> order;

		if (order == 1)
		{
			int val; cin >> val;
			stack.push(val);
		}
		else if (order == 2)
		{
			stack.pop();
		}
		else
		{
			if (stack.top >= mod)
				cout << stack.customFunc(mod) << '\n';
			else
				cout << -1 << '\n';
		}
	}

	return 0;
}