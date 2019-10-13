#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAX = 11;
ll prefix[MAX];

int main()
{
	ll n, k; cin >> n >> k;
	int res = 0;

	if (k < 10) {
		res = n < k ? -1 : k;
	}
	else {
		ll _pow = 1;
		for (int i = 1; i < MAX; i++) {
			prefix[i] = prefix[i - 1] + (_pow * 9 * i);
			_pow *= 10;
		}

		int idx = 0;
		while (idx < MAX && k > prefix[idx + 1]) 
			idx++;

		ll diff = k - prefix[idx];
		int pos = (diff - 1) % (idx + 1);
		ll value = pow(10, idx) + ( (diff-1) / (idx + 1));

		if (value >= n) res = -1;
		else {
			int digit[MAX + 1] = {};
			for (int i = 0; i < idx; i++) {
				digit[i] = value % 10;
				value /= 10;
			}

			res = digit[idx - pos];
		}
	}
	
	cout << res;


	return 0;
}