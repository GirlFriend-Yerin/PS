/*
	2019 04 15
	5670 휴대폰 자판
	Trie

	- 성공 -
*/
#include <iostream>

using namespace std;

const short charMAX = 80;
const int tcMAX = 100005;

struct myTrie {
	myTrie* child[26] = { nullptr, };
	int childCount = 0;
	bool wordExist = false;

	myTrie() {};
	~myTrie() { for (int i = 0; i < 26; i++) if (child[i] != nullptr) delete child[i]; }
};

struct myData {
	int count = 0;
	char inputs[tcMAX][charMAX + 1] = {};
};

void insertTrie(myTrie* root, char word[charMAX + 1])
{
	myTrie* cursor = root;
	for (int i = 0; word[i] != '\0'; i++) {
		if (cursor->child[word[i] - 'a'] == nullptr)
		{
			cursor->child[word[i] - 'a'] = new myTrie();
			cursor->childCount++;
		}

		cursor = cursor->child[word[i] - 'a'];
	}

	cursor->wordExist = true;
}

int countTrie(myTrie* root, char word[charMAX + 1]) {

	int count = 1;
	myTrie* cursor = root->child[word[0] - 'a'];
	int wordPos = 1;

	while (word[wordPos] != '\0' && cursor != nullptr)
	{
		if (cursor->childCount > 1 || cursor->wordExist)
			count++;
		cursor = cursor->child[word[wordPos] - 'a'];
		wordPos++;
	}

	return count;
}

double func(myData& md)
{
	double sum = 0;

	myTrie* root = new myTrie();

	for (int i = 0; i < md.count; i++)
		insertTrie(root, md.inputs[i]);

	for (int i = 0; i < md.count; i++)
	{
		int count = countTrie(root, md.inputs[i]);
		//cout << md.inputs[i] << " : " << count << '\n';
		sum += count;
	}

	delete root;

	return sum / md.count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count;

	while (cin >> count)
	{
		myData tcc;
		tcc.count = count;

		for (int i = 0; i < tcc.count; i++)
			cin >> tcc.inputs[i];

		double res = func(tcc);

		cout << fixed;
		cout.precision(2);

		cout << res << '\n';
	}

	return 0;
}