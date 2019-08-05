#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

int heap[MAX];
int nodeCount;

void mSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void push(int val)
{
	heap[nodeCount] = val;

	for (int pos = nodeCount; pos > 0; pos /= 2)
	{
		if (heap[pos] > heap[pos / 2])
			mSwap(heap[pos], heap[pos / 2]);
	}

	nodeCount++;
}

int pop()
{
	int ret = heap[0];

	heap[0] = heap[--nodeCount];

	for (int pos = 0; pos < nodeCount;)
	{
		if ((pos * 2) + 2 < nodeCount)
		{
			int biggerPos = heap[pos * 2 + 1] > heap[pos * 2 + 2] ? pos * 2 + 1 : pos * 2 + 2;

			if (heap[pos] < heap[biggerPos])
				mSwap(heap[pos], heap[biggerPos]);

			pos = biggerPos;
		}
		else if ((pos * 2) + 1 < nodeCount)
		{
			if (heap[pos] < heap[pos * 2 + 1])
				mSwap(heap[pos], heap[pos * 2 + 1]);

			pos = pos * 2 + 1;
		}
		else
			pos = pos * 2 + 1;
	}

	return ret;
}

int main()
{
	int n;
	vector<int> a;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;

		push(val);
	}

	for (int i = 0; i < n; i++)
		cout << pop() << endl;

	return 0;
}