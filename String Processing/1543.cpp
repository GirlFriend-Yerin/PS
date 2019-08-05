#include <iostream>
#include <string.h>

using namespace std;

const int DOC_MAX = 2500;
const int WORD_MAX = 50;

char document[DOC_MAX+1];
char word[WORD_MAX + 1];
int docLen, wordLen;

int correct(int pos, int& count)
{
	int cnt = pos;

	for (int i = 0; i < wordLen; cnt++, i++)
		if (word[i] != document[cnt])
			break;

	if (pos + wordLen == cnt)
	{
		count++;
		return wordLen;
	}

	return 1 ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count = 0;
	
	cin >> document >> word;
	docLen = strlen(document);
	wordLen = strlen(word);
	
	for (int i = 0; i < docLen; i++)
	{
		if (document[i] != word[0])
			continue;

		i += correct(i, count) -1 ;
	}

	cout << count;

	return 0;
}