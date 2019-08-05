#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> mHeap;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		mHeap.push(input);
	}

	cout << mHeap.top();


	return 0;
}