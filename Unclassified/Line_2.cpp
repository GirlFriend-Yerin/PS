#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	string input;
	int len;
	queue<string> sQ;
	queue<int> iQ;

	cin >> input;

	len = input.length();
	for (int pos = 0; pos < len; pos++)
	{
		char thisChar = input[pos];
		if ('A' <= thisChar && thisChar <= 'Z')
		{
			string res;
			res += thisChar;

			char nextChar = input[pos + 1];

			if ('a' <= nextChar && nextChar <= 'z')
			{
				res += nextChar;
				pos++;
			}
			sQ.push(res);
		}
		else
		{
			if (pos + 1 < len)
			{
				char nextChar = input[pos + 1];
				if (nextChar != '0')
					iQ.push(thisChar - '0');
				else
				{
					iQ.push(10);
					pos++;
				}
			}
			else
				iQ.push(thisChar - '0');
		}
	}

	if (iQ.size() != sQ.size())
		cout << "error";
	else {
		while (!sQ.empty())
		{
			cout << sQ.front();
			sQ.pop();
			int count = iQ.front();
			iQ.pop();
			if (count != 1)
				cout << count;
		}
	}

	return 0;
}