#include <iostream>
#include <vector>

using namespace std;

struct {
	int hp;
	int mp;
	int atk;
	int arm;
	int pow;

	void calPow() {
		pow = (1 * hp) + (mp * 5) + (atk * 2) + (arm * 2);
	}
	
}typedef Stat;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<Stat> input(n);

	for (int i = 0; i < n; i++) {
		cin >> input[i].hp >> input[i].mp >> input[i].atk >> input[i].arm;
		int it_hp, it_mp, it_atk, it_arm; cin >> it_hp >> it_mp >> it_atk >> it_arm;
		input[i].hp = input[i].hp + it_hp < 1 ? 1 : input[i].hp + it_hp;
		input[i].mp = input[i].mp + it_mp < 1 ? 1 : input[i].mp + it_mp;
		input[i].atk = input[i].atk + it_atk < 0 ? 0 : input[i].atk + it_atk;
		input[i].arm += it_arm;
		input[i].calPow();

		cout << input[i].pow << '\n';
	}

	return 0;
}