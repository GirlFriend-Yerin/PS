#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N_MAX = 100000;
const short ALPHA_MAX = 26;
const short STR_MAX = 21;

struct PokeData {
	char* data;
	int number;

	PokeData() {};
	PokeData(char* data, int num) : data(data), number(num) {};
};

int n, m;
vector<PokeData> vec_poke;
char pokemons[N_MAX][STR_MAX];

bool cmp(const PokeData& p1, const PokeData& p2) {
	int pos = 0;
	while (p1.data[pos] != '\0' && p2.data[pos] != '\0') {
		if (p1.data[pos] > p2.data[pos])
			return false;
		else if (p1.data[pos] < p2.data[pos])
			return true;
		pos++;
	}

	return p1.data[pos] == '\0' ? true : false;
}

bool c_cmp(const char* c1, const char *c2) {
	int pos = 0;
	while (c1[pos] != '\0' && c2[pos] != '\0') {
		if (c1[pos] > c2[pos])
			return false;
		else if (c1[pos] < c2[pos])
			return true;
		pos++;
	}

	return c1[pos] == '\0' ? true : false;
}

int findPoke(char name[STR_MAX]) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (c_cmp(vec_poke[middle].data, name))
			left = middle + 1;
		else
			right = middle -1;
	}

	return vec_poke[right].number;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vec_poke.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> pokemons[i];
		vec_poke[i] = PokeData(pokemons[i], i + 1);
	}

	sort(vec_poke.begin(), vec_poke.end(), cmp);

	for (int j = 0; j < m; j++) {
		char input[STR_MAX] = {};
		cin >> input;

		if ('0' <= input[0] && input[0] <= '9')
		{
			int idx = atoi(input);
			cout << pokemons[idx - 1] << '\n';
		}
		else
		{
			cout << findPoke(input) << '\n';
		}
	}

	return 0;
}