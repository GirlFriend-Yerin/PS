#include <iostream>

using namespace std;

const int MAX = 1000;

bool check[MAX + 1];
int phi[MAX + 1] = { 0, 0 };

void init() {

	phi[1] = 1;

	for (int i = 2; i <= MAX +1; i++) {
		if (!phi[i]) {
			for (int j = i; j <= MAX + 1; j += i) {
				if (!phi[j]) {
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
	// ´©Àû°ª 
	for (int i = 2; i <= MAX + 1; i++) {
		phi[i] += phi[i - 1];
	}
}


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	int n; cin >> n;

	init();

	for (int i = 0; i < n; i++){
		int val; cin >> val;
	
		cout << 1 + (phi[val] * 2) << '\n';
	}

	return 0;
}