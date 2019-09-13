#include <iostream>
#include <string>

using namespace std;

const short MAX = 30000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string plain; getline(cin ,plain);
	string key; cin >> key;
	
	int plainLen = plain.length();
	int keyLen = key.length();

	for (int i = 0; i < plain.size(); i++) {
		if (plain[i] != ' ') {
			plain[i] -= key[i % keyLen] - 'a' + 1;
			plain[i] += plain[i] < 'a' ? 26 : 0;
		}
	}

	cout << plain;

	return 0;
}