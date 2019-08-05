#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	for (int i = 0; i < a.length() / 2; i++)
		swap(a[i], a[a.length() - (i + 1)]);

	for (int i = 0; i < b.length() / 2; i++)
		swap(b[i], b[b.length() - (i + 1)]);

	string res = to_string(stoi(a) + stoi(b));

	for (int i = 0; i < res.length() / 2; i++)
		swap(res[i], res[res.length() - (i + 1)]);

	cout << stoi(res);

	return 0;
}