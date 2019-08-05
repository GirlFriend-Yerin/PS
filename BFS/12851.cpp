#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

bool visited[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int start, end;
	int res = 0, sameCount = 0;
	
	cin >> start >> end;

	bool isOver = false;
	queue<int> q;
	queue<int> nQ;

	q.push(start);

	if (start > end) {
		isOver = true;
		res = start - end;
		sameCount = 1;
	}

	while (!isOver) {
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			visited[cur] = true;

			if (cur == end) {
				sameCount++;
				isOver = true;
			}

			if (cur + 1 < MAX && !visited[cur + 1])
				nQ.push(cur + 1);
			if (cur - 1 >= 0 && !visited[cur - 1])
				nQ.push(cur - 1);
			if (cur != 0 && cur * 2 < MAX && !visited[cur * 2])
				nQ.push(cur * 2);
		}

		if (isOver)
			continue;

		res++;

		while (!nQ.empty()) {
			q.push(nQ.front());
			nQ.pop();
		}
	}

	cout << res << '\n' << sameCount;

	return 0;
}