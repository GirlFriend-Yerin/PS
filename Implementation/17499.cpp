#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int pos = 0;
	for (int i = 0; i < q; i++) {
		int order, relPos; cin >> order >> relPos;

		switch (order)
		{
		case 1: {
			int x; cin >> x;
			int abPos = (pos + relPos - 1 + n) % n;
			arr[abPos] += x;
		}
			break;
		case 2: 
			pos = (pos - relPos + n) % n;
			break;
		case 3:
			pos = (pos + relPos) % n;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[(pos + i) % n] << ' ';

	return 0;
}