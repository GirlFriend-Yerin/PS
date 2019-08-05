#include <iostream>

using namespace std;

const int ORDER_MAX = 100000;
const int MEM_MAX = 1000;

struct GoStack {
	long long mem[MEM_MAX] = {};
	int pos = 0;

	void push(long long val) { mem[pos++] = val; }
	void pop(long long val) {  }
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool timeFlag = false;

	return 0;
}