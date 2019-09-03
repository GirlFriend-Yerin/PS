#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const short MAX = 1000;

int _min(const int a, const int b) { return b ^ ((a^b) & -(a < b)); }

string preprocessing(const string& str) {

	string res;
	for (int i = 0; str[i] != '\0'; i++) {
		char ch = str[i];

		res.push_back(('a' <= ch && ch <= 'z') ? ch - ('a' - 'A') : ch);
	}

	return res;
}

vector<int> makeHashSet(const string& str) {

	int strLen = str.length();
	vector<int> resSet;

	for (int i = 0; i < strLen - 1; i++) {
		if (('A' <= str[i] && str[i] <= 'Z') && ('A' <= str[i + 1] && str[i + 1] <= 'Z'))
			resSet.push_back(str[i] * 100 + str[i + 1]);
	}

	sort(resSet.begin(), resSet.end());

	return resSet;
}

int AcupB(const vector<int>& setA, const vector<int>& setB, vector<int>& unionSet, vector<int>& cupSet) {

	int pivotA = 0;
	int pivotB = 0;
	int res = 0;
	const int sizeA = setA.size();
	const int sizeB = setB.size();

	while (pivotA < sizeA && pivotB < sizeB) {
		int min = _min(setA[pivotA], setB[pivotB]);

		if (setA[pivotA] == setB[pivotB]) {
			cupSet.push_back(setA[pivotA]);
			res++;
		}

		pivotA += min == setA[pivotA];
		pivotB += min == setB[pivotB];

		unionSet.push_back(min);
	}

	while (pivotA < sizeA) unionSet.push_back(setA[pivotA++]);
	while (pivotB < sizeB) unionSet.push_back(setB[pivotB++]);

	return res;
}

void printHash(vector<int> hash) {
	for (auto val : hash) {
		cout << char(val / 100) << char(val % 100) << endl;
	}
}

int solution(string str1, string str2) {
	vector<int> setA = makeHashSet(preprocessing(str1));
	vector<int> setB = makeHashSet(preprocessing(str2));
	vector<int> unionSet;
	vector<int> cupSet;

	int cup = AcupB(setA, setB, unionSet, cupSet);

	double ratio = unionSet.size() ? (double(cup) / (unionSet.size())) : 1;

	/*printHash(setA);
	cout << "----------------" << endl;
	printHash(setB);
	cout << "----------------" << endl;
	printHash(unionSet);
	cout << "----------------" << endl;
	printHash(cupSet);*/

	return ratio * 65536;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1 = "E=M*C^2" ;
	string str2 = "e=m*c^2";

	//string str1, str2; cin >> str1 >> str2;

	cout << solution(str1, str2);

	return 0;
}