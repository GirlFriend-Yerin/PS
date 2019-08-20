#include <iostream>
#include <string>

using namespace std;

short chain[] = { 'C' - 'A','H' - 'A','I' - 'A','C' - 'A','K' - 'A','E' - 'A','N' - 'A','S' - 'A' };

void updateChain() {

	chain[0] = (chain[0] + 1) % 26;
}

short convert(int pos, short val)
{
	if (pos == 8)
		return val;
	else
		return convert(pos + 1, (val + chain[pos]) % 26);
}

int main()
{
	string input; cin >> input;
	string res;

	for (int i = 0; i < input.size(); i++)
	{
		res += 'A' + convert(0, input[i] - 'A');
		updateChain();
	}

	cout << res;
	return 0;
}