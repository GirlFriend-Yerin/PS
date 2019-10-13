#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	double total = 0;
	string tree;
	map<string, int> dic;
	while(getline(cin, tree)){
		if (dic.find({ tree, 1 }) != dic.end())
			dic.insert({ tree, 1 });
		else
			dic[tree]++;
		total++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto it = dic.begin(); it != dic.end(); it++) {
			cout << it->first << ' ' << it->second * 100 / total <<'\n';
	}

	return 0;
}