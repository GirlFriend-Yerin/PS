#include <iostream>

using namespace std;

const int MAX = 1000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int val[MAX] = {};

	for (int i = 0; i < n; i++)
		cin >> val[i];

	for (int i = 0; i < n; i++) {
		double vMin = 0;
		double vMinPos = 1;
		int sum = 0; for (int j = 0; j < i + 1; j++) sum += val[j];
		int left = 0, right = i;

		while (right < n) {
			double avg = sum / double(right - left + 1);
			double vSum = 0;
			for (int j = left; j <= right; j++)
				vSum += (val[j] - avg) * (val[j] - avg);
			double v = vSum / (right - left + 1);
			if (vMin < v) {
				vMin = v;
				vMinPos = left + 1;
			}

			sum += val[++right] - val[left++];
		}

		cout << vMinPos << '\n';
	}

	return 0;
}