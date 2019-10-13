#include <iostream>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int order2Int(string& s) {

	switch (s[0])
	{
	case'N': return 0;
	case 'P': return 1;
	case 'I': return 2;
	case 'D': return s[1] == 'U' ? 3 : 8;
	case 'S': return s[1] == 'W' ? 4 : 6;
	case 'A': return 5;
	case 'M': return s[1] == 'U' ? 7 : 9;
	}

	return -1;
}

typedef pair<int, int> pii;
typedef long long ll;

pii run(const vector<pii>& order, int start) {

	stack<int> goStk;

	goStk.push(start);

	bool error = false;
	for (const pii& od : order) {
		if (error) break;

		switch (od.first)
		{
		case 0: goStk.push(od.second); break;
		case 1: 
			if (goStk.empty()) error = true;
			else goStk.pop(); 
			break;
		case 2: {
			if (goStk.empty()) error = true;
			else {
				int val = -goStk.top(); goStk.pop();
				goStk.push(val);
			}
			break;
		}
		case 3: 
			if (goStk.empty()) error = true;
			else goStk.push(goStk.top());
			break;
		case 4: {
			if (goStk.size() < 2) error = true;
			else {
				int one = goStk.top(); goStk.pop();
				int two = goStk.top(); goStk.pop();
				goStk.push(one); goStk.push(two);
			}
			break;
		}
		case 5: {
			if (goStk.size() < 2) error = true;
			else {
				int one = goStk.top(); goStk.pop();
				int two = goStk.top(); goStk.pop();
				int sum = one + two;
				if (-1e9 <= sum && sum <= 1e9) goStk.push(one + two); 
				else error = true;
			}
			break;
		}
		case 6: {
			if (goStk.size() < 2) error = true;
			else {
				int one = goStk.top(); goStk.pop();
				int two = goStk.top(); goStk.pop();
				int sub = two - one;
				if ( -1e9 <= sub && sub <= 1e9) goStk.push(sub); 
				else error = true;
			}

			break;
		}
		case 7: {
			if (goStk.size() < 2) error = true;
			else {
				ll one = goStk.top(); goStk.pop();
				ll two = goStk.top(); goStk.pop();
				ll mul = one * two;

				if (-1e9 <= mul && mul <= 1e9) goStk.push(mul);
				else error = true;
			}

			break;
		}
		case 8: {
			if (goStk.size() < 2) error = true;
			else {
				ll one = goStk.top(); goStk.pop();
				ll two = goStk.top(); goStk.pop();

				if (!one) goStk.push(two / one);
				else error = true;
			}

			break;
		}
		case 9: {
			if (goStk.size() < 2) error = true;
			else {
				int one = goStk.top(); goStk.pop();
				int two = goStk.top(); goStk.pop();
				if (!one) goStk.push(two % one);
				else error = true;
			}

			break;
		}
		default:
			break;
		}
	}

	error = error | (goStk.size() > 1);

	return pii{ error, { error ? 0 : goStk.top() } };
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (true) {
		vector<pii> order;
		
		string str; cin >> str;
		if (str == "QUIT") break;

		while (str != "END") {
			int oi = order2Int(str);
			int val = 0;
			if (!oi) cin >> val;
			order.push_back({ oi , val });
			cin >> str;
		}

		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int val; cin >> val;
			pii res = run(order, val);
			if (res.first) cout << "ERROR\n";
			else cout << res.second << '\n';
		}
	}

	return 0;
}