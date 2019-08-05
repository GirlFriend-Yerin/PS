#include <iostream>

using namespace std;

const int DAY_MAX = 1e5;
const int NUT_MAX = 30;

bool check(int arr[NUT_MAX], int len) {
	for (int i = 1; i < len; i++)
		if (arr[i] != arr[i - 1])
			return false;
	return true;
}
void subSum(int* tar, int* min, int* max, int len) {
	for (int i = 0; i < len; i++)
		tar[i] = max[i] - min[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {

		int n, k; cin >> n >> k;
		int* preSum[DAY_MAX + 1]; 
		for (int i = 0; i < n + 1; i++) 
		{
			preSum[i] = new int[k];
			for (int j = 0; j < k; j++)
				preSum[i][j] = 0;
		}

		for (int i = 1; i < n + 1; i++)
			for (int j = 0; j < k; j++)
			{
				bool input; cin >> input;
				preSum[i][j] = preSum[i - 1][j] + input;
			}

		int maxLen = 0;
		int res = 0;

		for (int i = n; i > 0; i--) {
			for (int j = 0; j < i; j++)
			{
				int arr[NUT_MAX];

				subSum(arr, preSum[j], preSum[i], k);
				if (check(arr, k))
				{
					int len = i - j;
					maxLen = maxLen < len ? len : maxLen;
					res++;
				}
			}
		}

		cout << '#' << tc << ' ' << maxLen << ' ' << res <<'\n';

		for (int i = 0; i < n; i++) delete preSum[i];
	}
	return 0;
}