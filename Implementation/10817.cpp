#include <iostream>
#include <vector>

using namespace std;

float avg(const vector<float>& vec) {

	float sum = 0;
	for (int i = 0; i < vec.size(); i++) sum += vec[i];

	return sum / vec.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc; cin >> tc;

	while (tc--) {
		int n; cin >> n;
		int cnt = 0;

		vector<float> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
		float av = avg(vec);

		for (int i = 0; i < n; i++) cnt += vec[i] > av;

		printf("%.3f%%\n", float(cnt) / n * 100);
		
	}

	return 0;
}