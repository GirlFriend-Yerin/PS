#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const short MAX = 26;
const short LEN_MAX = 100;

int val[MAX];

int main()
{
	int n; cin >> n;
	char input[LEN_MAX + 1] = {}; cin >> input;
	for (int i = 0; i < n; i++)
		cin >> val[i];

	stack<double> cal;

	for (int i = 0; input[i]; i++) {
		if ('A' <= input[i] && input[i] <= 'Z')
			cal.push(val[input[i] - 'A']);
		else {
			double right = cal.top(); cal.pop();
			double left = cal.top(); cal.pop();
			switch (input[i])
			{
			case '+':
				cal.push(left + right);
				break;
			case '-':
				cal.push(left - right);
				break;
			case '/':
				cal.push(left / right);
				break;
			case '*':
				cal.push(left * right);
				break;
			}
		}
	}

	printf("%.2f", cal.top());
}