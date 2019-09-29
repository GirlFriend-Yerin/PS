#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


typedef pair<int, int> pii;

struct Data {
	int sum;
	pii pos;

	Data(int sum) : sum(sum), pos({ 0, 0 }) {};
	Data(int sum, pii pos) : sum(sum), pos(pos) {};

	bool operator< (const Data& data) { return sum < data.sum; }
};

int _lower_bound(const vector<Data>& data, int val) {
	
	int left = 0;
	int right = data.size();

	while (left < right) {
		int mid = (left + right) / 2;

		if (data[mid].sum < val)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int _upper_bound(const vector<Data>& data, int val) {

	int left = 0;
	int right = data.size();

	while (left < right) {
		int mid = (left + right) / 2;

		if (data[mid].sum <= val)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, n; cin >> w >> n;
	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];

	vector<Data> data;

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) data.push_back(Data(vec[i] + vec[j], { i, j }));

	int dataSize = data.size();
	sort(data.begin(), data.end());

	bool res = false;

	for (int i = 0; i < dataSize; i++) {
		if (w <= data[i].sum) continue;
		int tar = w - data[i].sum;

		int lower = _lower_bound(data, tar);
		int upper = _upper_bound(data, tar);

		for (int j = lower; j < upper; j++) {
			if (tar != data[j].sum) continue;
			if (data[i].pos.first == data[j].pos.first
				|| data[i].pos.first == data[j].pos.second
				|| data[i].pos.second == data[j].pos.first
				|| data[i].pos.second == data[j].pos.second)
				continue;
			res = true;
			break;
		}

		if (res) break;
	}

	cout << (res ? "YES" : "NO");

	return 0;
}