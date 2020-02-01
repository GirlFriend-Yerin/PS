#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHA_MAX = 26;
const int N_MAX = 50;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

vector<int> mem[50];
vector<int> newAlpha;
int board;
int res, n, k;

bool isPrimary(char ch)
{
	return ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c';
}

bool isAble(int idx)
{
	for (int i = 0; i < mem[idx].size(); i++)
		if (!(board & (1 << mem[idx][i]))) return false;
	return true;
}

int ableCount()
{
	int ret = 0;

	for (int i = 0; i < n; i++)
		ret += isAble(i);

	return ret;
}

void bruteForce(int pos, int cnt, const int& bound)
{
	if (cnt == bound)
	{
		res = _max(res, ableCount());
		return;
	}

	for (int i = pos; i < newAlpha.size(); i++) {
		board ^= (1 << newAlpha[i]);
		bruteForce(i + 1, cnt + 1, bound);
		board ^= (1 << newAlpha[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int check = board = 1 ^ (1 << ('n' - 'a')) ^ (1 << ('t' - 'a')) ^ (1 << ('i' - 'a')) ^ (1 << ('c' - 'a'));

	cin >> n >> k;

	if (k == 26) res = n;
	else if (k > 4)
	{
		for (int i = 0; i < n; i++)
		{
			string str; cin >> str;

			int len = str.length();
			for (int j = 4; j < len - 4; j++) {
				int pos = str[j] - 'a';
				if (!isPrimary(str[j])) mem[i].push_back(pos);
				if (!(check & (1 << pos))) newAlpha.push_back(pos);
				check |= 1 << pos;
			}
		}

		if (newAlpha.size() <= k - 5) res = n;
		else bruteForce(0, 0, k - 5);
		
	}

	cout << res;

	return 0;
}