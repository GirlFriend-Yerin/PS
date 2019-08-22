#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	cin.ignore();

	while (tcc--) {
		string total;
		vector<string> says;
		vector<string> totalSay;

		getline(cin, total);

		string temp = "";
		for (int pT = 0; total[pT] != '\0'; pT++) {
			if (total[pT] == ' ') {
				totalSay.push_back(temp);
				temp = "";
			}
			else
				temp += total[pT];
		}
		totalSay.push_back(temp);

		string input; getline(cin, input);
		while (input != "what does the fox say?") {
			string say = input.substr(input.find("goes ") + 5);
			says.push_back(say);

			getline(cin, input);
		}

		for (string say : totalSay) {
			bool checker = true;

			for (string check : says) {
				if (check == say) {
					checker = false;
					break;
				}
			}

			if (checker)
				cout << say << ' ';
		}

		cout << '\n';
	}

	return 0;
}