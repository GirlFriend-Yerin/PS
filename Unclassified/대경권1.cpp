#include <iostream>
#include <string>
#include <vector>

using namespace std;

int timeToInt(string s) {

	int hour = stoi(s.substr(0,2));
	int min = stoi(s.substr(3));

	return hour * 60 + min;
}

string intToTime(int t) {
	int hour = t / 60;
	int min = t - ((t / 60) * 60);

	string res;
	if (hour < 10)
		res = "0";
	res += to_string(hour) + ":";
	if (min < 10)
		res += "0";
	res += to_string(min);

	return res;
}

int main()
{
	string curtime_s;
	int x, y;

	cin >> curtime_s >> x >> y;

	int curtimei = timeToInt(curtime_s);

	int first, second;

	cin >> first >> second;

	vector<string> vec_first(first), vec_second(second);

	for (int i = 0; i < first; i++)
		cin >> vec_first[i];

	for (int i = 0; i < second; i++)
		cin >> vec_second[i];

	int near;

	for (int i = 0; i < first; i++) {
		int calTime = timeToInt(vec_first[i]);
		if (calTime >= curtimei) {
			curtimei = calTime;
			break;
		}
	}

	curtimei += x;

	for (int i = 0; i < second; i++){
		int calTime = timeToInt(vec_second[i]);
		if (calTime >= curtimei) {
			curtimei = calTime;
			break;
		}
	}

	curtimei += y;

	cout << intToTime(curtimei);

	return 0;
}