/*
	2019 04 23
	1931 회의실 배정
	그리디 알고리즘

	- 성공 - 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MeetTime {
	int start;
	int end;

	MeetTime() {};
	MeetTime(int start, int end) : start(start), end(end) {};
};

bool cmp(MeetTime& mt1, MeetTime& mt2) {
	if (mt1.end > mt2.end)
		return false;
	else if (mt1.end == mt2.end) {
		if (mt1.start > mt2.start)
			return false;
		else if (mt1.start == mt2.start)
			return false;
	}
	return true;
}

vector<MeetTime> times;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	times.resize(n);

	for (int i = 0; i < n; i++)
		cin >> times[i].start >> times[i].end;

	sort(times.begin(), times.end(), cmp);

	int startTime = times[0].start, endTime = times[0].end;
	int res = 1;

	for (int i = 1; i < n; i++) {
		MeetTime mt = times[i];
		if (endTime <= mt.start ) {
			endTime = mt.end;
			res++;
		}
	}

	cout << res;

	return 0;
}