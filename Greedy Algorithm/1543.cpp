#include <iostream>
#include <string>

using namespace std;

bool compare(string& input, string& word, int pos, int len) {

	for (int i = 0; i < len; i++)
		if (input[pos + i] != word[i])
			return false;
	return true;
}

int main()
{
	string input, word;

	getline(cin, input);
	getline(cin, word);

	cin >> input >> word;

	int inputLen = input.length();
	int wordLen = word.length();
	int res = 0;

	for (int i = 0; i <= inputLen - wordLen;) {
		if (input[i] == word[0]) {
			if (compare(input, word, i, wordLen)) {
				res++;
				i += wordLen;
			}
			else
				i++;
		}
		else
			i++;
	}

	cout << res;

	return 0;
}