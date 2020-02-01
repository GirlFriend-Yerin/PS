#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<int> dq;
	int n; cin >> n;

	while (n--)
	{
		string order; cin >> order;
		if (order == "push_front")
		{
			int val; cin >> val;
			dq.push_front(val);
		}
		else if (order == "push_back")
		{
			int val; cin >> val;
			dq.push_back(val);
		}
		else if (order == "pop_front") {
			int val = -1;
			if (!dq.empty()) {
				val = dq.front();
				dq.pop_front();
			}
			cout << val << '\n' ;
		}
		else if (order == "pop_back") {
			int val = -1;
			if (!dq.empty()) {
				val = dq.back();
				dq.pop_back();
			}
			cout << val << '\n' ;
		}
		else if (order == "size") {
			cout << dq.size() << '\n';
		}
		else if (order == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (order == "front") {
			int val = -1;
			if (!dq.empty()) val = dq.front();
			cout << val << '\n' ;
		}
		else if (order == "back") {
			int val = -1;
			if (!dq.empty()) val = dq.back();
			cout << val << '\n';
		}

	}

	return 0;
}