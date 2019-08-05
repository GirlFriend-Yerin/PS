#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int alphaTop[26] = {}, alphaBot[26] = {}, res = 0;

	string top, bot;

	cin >> top >> bot;

	for (int i = 0; i < top.size(); i++)
		alphaTop[top[i] - 'a']++;
	for (int i = 0; i < bot.size(); i++)
		alphaBot[bot[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		res += abs(alphaTop[i] - alphaBot[i]);

	cout << res;

	return 0;
}