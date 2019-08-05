#include <iostream>
#include <queue>

using namespace std;

// 아호코라식

const short INPUT_LEN_MAX = 100;
const short INPUT_MAX = 1000;
const short QUERY_LEN_MAX = 10000;
const short QUERY_MAX = 1000;
const short ALPHA_MAX = 26;

struct Trie {
	Trie* go[ALPHA_MAX];
	Trie* fail;
	bool exist;

	Trie() {
		exist = false;
		for (int i = 0; i < ALPHA_MAX; i++)
			go[i] = nullptr;
	}

	~Trie() {
		for (int i = 0; i < ALPHA_MAX; i++)
			if (go[i])
				delete go[i];
	}

	void insert(char *str) {
		if (*str == '\0') {
			exist = true;
			return;
		}
		int next = *str - 'a';
		if (!go[next])
			go[next] = new Trie();
		go[next]->insert(str + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Trie* trie = new Trie();

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		char inputs[INPUT_LEN_MAX + 1] = {};
		cin >> inputs;

		trie->insert(inputs);
	}

	// Fail
	queue<Trie*> q;
	trie->fail = trie;
	q.push(trie);

	while (!q.empty()) {
		Trie* cur = q.front(); q.pop();

		for (int i = 0; i < ALPHA_MAX; i++) {
			Trie* next = cur->go[i];
			if (!next)
				continue;
			if (cur == trie) next->fail = trie;
			else {
				Trie* des = cur->fail;

				while (des != trie && !des->go[i])
					des = des->fail;

				if (des->go[i]) des = des->go[i];
				next->fail = des;
			}

			if (next->fail->exist) next->exist = true;

			q.push(next);
		}
	}

	int s; cin >> s;

	for (int i = 0; i < s; i++) {

		char inputs[QUERY_LEN_MAX + 1] = {};
		cin >> inputs;

		Trie* findNode = trie;
		bool res = false;

		for (int pos = 0; inputs[pos]; pos++) {
			int next = inputs[pos] - 'a';

			while (findNode != trie && !findNode->go[next])
				findNode = findNode->fail;

			if (findNode->go[next])
				findNode = findNode->go[next];

			if (findNode->exist) {
				res = true;
				break;
			}
		}

		cout << (res ? "YES" : "NO") << '\n';
	}

	delete trie;

	return 0;
}