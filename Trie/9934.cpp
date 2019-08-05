/*
	2019 04 15
	9934 완전 이진트리
	Trie

	- 성공 -
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1024;

int trie[MAX];

struct Queue {
	int head = 0;
	int tail = 0;
	int data[100000];

	void push(int val) {
		data[head++] = val;
	}

	int pop() {
		return data[tail++];
	}

	bool isEmpty() {
		return head == tail;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;
	int nodeCount = pow(2, tcc) - 1;
	int depth = pow(2, tcc - 2);

	for (int i = 0; i < nodeCount + 1; i++)
		cin >> trie[i];

	Queue q;
	Queue nQ;

	q.push(nodeCount / 2);

	while (!q.isEmpty())
	{
		while (!q.isEmpty()) {
			int cur = q.pop();

			cout << trie[cur] << ' ';

			if (depth == 0)
				continue;

			int left = cur - depth;
			int right = cur + depth;

			if (0 <= left)
				nQ.push(left);
			if (right <= nodeCount)
				nQ.push(right);
		}

		depth /= 2;
		cout << '\n';

		while (!nQ.isEmpty()) {
			q.push(nQ.pop());
		}
	}

	return 0;
}