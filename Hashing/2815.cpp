#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int res = -1;

	string input; cin >> input;

	vector<string> encVec;
	vector<string> realVec;
	vector<bool> encPat;
	vector<bool> realPat;

	while (input != "$") {
		encVec.push_back(input);
		cin >> input;
	}

	cin >> input;
	while (input != "$") {
		realVec.push_back(input);
		cin >> input;
	}

	for (int i = 0; i < encVec.size() - 1; i++)
		encPat.push_back(encVec[i + 1] == encVec[i]);

	for (int i = 0; i < realVec.size() - 1; i++)
		realPat.push_back(realVec[i + 1] == realVec[i]);

	for (int i = 0; i < encPat.size(); i++) {
		if (encPat[i] == realPat[0]) {
			bool checker = true;

			for (int j = 1; j < realPat.size(); j++) {
				if (encPat[i + j] != realPat[j])
				{
					checker = false;
					break;
				}
			}

			if (checker)
			{
				res = i + 1;
				break;
			}
		}
	}

	cout << res;
		
	return 0;
}