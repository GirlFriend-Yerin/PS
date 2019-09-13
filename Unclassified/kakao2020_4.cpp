#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt(const vector<string>& words, const string& query) {
	int qLen = query.length();
	vector<bool> checker(words.size(), true);

	for (int i = 0; i < words.size(); i++)
		checker[i] = words[i].length() == query.length();

	for (int i = 0; i < qLen; i++) {
		if (query[i] == '?') continue;
		for (int j = 0; j < words.size(); j++) {
			if (!checker[j]) continue;	
			checker[j] = words[j][i] == query[i];
		}
	}

	int res = 0; for (bool status : checker) res += status;

	return res;
}


vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (auto& query : queries)
		answer.push_back(cnt(words, query));

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, q; cin >> w >> q;

	vector<string> words(w); for (int i = 0; i < w; i++) cin >> words[i];
	vector<string> queries(q); for (int i = 0; i < q; i++) cin >> queries[i];

	vector<int> sol = solution(words, queries);

	for (int counter : sol) {
		cout << counter << endl;
	}

	return 0;
}