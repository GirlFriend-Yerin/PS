/*
	2019 02 12
	6324 URLs
	문자열 처리

	- 성공 -
*/
#include <iostream>
#include <string>

using namespace std;

const string protocolTag = "://";

void func(string& str, int number)
{
	string protocol, host, port, path;
	int protocolPos = str.find(protocolTag);
	
	protocol = str.substr(0, protocolPos);

	int portPos = str.find(":", protocolPos + 3);
	int pathPos = str.find("/", protocolPos + 3);

	if (portPos == string::npos && pathPos == string::npos)
	{
		host = str.substr(protocolPos + 3);
		port = path = "<default>";
	}
	else if (portPos != string::npos)
	{
		host = str.substr(protocolPos + 3, portPos - protocolPos - 3);

		if (pathPos != string::npos && portPos < pathPos)
		{
			port = str.substr(portPos + 1, pathPos - portPos -1);
			path = str.substr(pathPos + 1);
		}
		else if (pathPos != string::npos && portPos > pathPos)
		{
			host = str.substr(protocolPos + 3, pathPos - protocolPos - 3);
			port = "<default>";
			path = str.substr(pathPos + 1);
		}
		else
		{
			port = str.substr(portPos + 1);
			path = "<default>";
		}
	}
	else
	{
		host = str.substr(protocolPos + 3, pathPos - protocolPos - 3);
		path = str.substr(pathPos+1);
		port = "<default>";
	}

	cout << "URL #" << number << '\n';
	cout << "Protocol = " << protocol << '\n';
	cout << "Host     = " << host << '\n';
	cout << "Port     = " << port << '\n';
	cout << "Path     = " << path << '\n';
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;

		cin >> input;

		func(input, i + 1);
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}