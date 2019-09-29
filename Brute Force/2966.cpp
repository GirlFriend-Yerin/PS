#include <iostream>

using namespace std;

const int MAX = 100;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	char input[MAX + 1] = {}; cin >> input;
	int sum[3] = {};
	const char* name[3] = { "Adrian" , "Bruno", "Goran" };

	for (int i = 0; i < n; i++) 
		sum[0] += input[i] == (i % 3)+ 'A';

	for (int i = 0; i < n; i++)
		sum[1] += input[i] == ((1 + ((i % 2) * ((i / 2) % 2 ? 1 : -1))) + 'A');

	const int check[6] = { 2,2,0,0,1,1 };;
	for (int i = 0; i < n; i++)
		sum[2] += input[i] == (check[i % 6] + 'A');

	int calMax = _max(_max(sum[0], sum[1]), sum[2]);

	cout << calMax << '\n';
	for (int i = 0; i < 3; i++)
		if (calMax == sum[i]) cout << name[i] << '\n';
	

	return 0;
}