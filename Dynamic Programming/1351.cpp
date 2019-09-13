#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> memo;
ll n, p, q;

ll func(ll n) {
	if (memo.count(n))
		return memo[n];
	
	return memo[n] = func(n / p) + func(n / q);
}

int main() {

	cin >> n >> p >> q;

	memo[0] = 1;

	cout << func(n);

	return 0;
}