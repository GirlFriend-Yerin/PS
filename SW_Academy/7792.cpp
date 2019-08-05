#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const short STU_MAX = 100;
const short NAME_MAX = 20;
const short ALPHA_MAX = 26;

int alphaCheck(string str) {
	int res = 0;
	bool check[ALPHA_MAX] = {};

	for (int i = 0; str[i]; i++) {
		if (str[i] != ' ' && str[i] != '\r' && !check[str[i] - 'A']) {
			check[str[i] - 'A'] = true;
			res++;
		}
	}
	return res;
}

struct Data{
	string name;
	int alphaCount;

	Data() { name = "", alphaCount = 0; }
	Data(string n, int a) : name(n), alphaCount(a) {};
};

bool cmp(Data& d1, Data& d2) {
	if (d1.alphaCount != d2.alphaCount)
		return d1.alphaCount < d2.alphaCount;

	return d1.name < d2.name;
}

int main()
{
	int tcc; scanf("%d", &tcc);

	for (int tc = 1; tc <= tcc; tc++) {
		int n; scanf(" %d ", &n);
		vector<Data> names(n);

		for (int i = 0; i < n; i++) {
			char name[NAME_MAX] = {};
			scanf(" %[^\n] ", &name);
			names[i].name = string(name);
			names[i].alphaCount = alphaCheck(names[i].name);
		}

		sort(names.begin(), names.end(), cmp);

		printf("#%d %s\n", tc, names[0].name.c_str());
	}

	return 0;
}