#include <iostream>

using namespace std;

const int MAX = 200000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int input[MAX + 1] = {};
	char res[MAX + 1] = {};
	int cnt = 0;

	// 351 1008 8241 83 20900

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i];

	int leftPivot = 0;
	int rightPivot = n - 1;
	int last = 0;

	for (int i = 0; (input[rightPivot] >= last || input[leftPivot] > last) && i < n; i++) {
		if (input[leftPivot] > last && input[rightPivot] > last) {
			if (input[leftPivot] <= input[rightPivot]) {
				res[cnt++] = 'L';
				last = input[leftPivot++];
			}
			else {
				res[cnt++] = 'R';
				last = input[rightPivot--];
			}
		}
		else if (input[leftPivot] < last)
		{
			res[cnt++] = 'R';
			last = input[rightPivot--];
		}
		else if (input[rightPivot] < last) {
			res[cnt++] = 'L';
			last = input[leftPivot++];
		}
	}

	cout << cnt << '\n' << res;
	return 0;
}