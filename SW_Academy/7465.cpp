#include <iostream>

using namespace std;

const int MAX = 100000;
const int nMax = 100;

struct Queue
{
	int top = 0;
	int rear = 0;
	int data[MAX];

	void push(int val) {
		data[top++ % MAX] = val;
	}

	int pop() {
		return data[rear++ % MAX];
	}

	bool isEmpty() {
		return top == rear;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;

	cin >> tcc;

	for (int tn = 1; tn <= tcc; tn++)
	{
		int n, m;
		int res = 0;
		cin >> n >> m;

		bool adj[nMax][nMax] = {};
		bool visited[nMax] = {};

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a - 1][b - 1] = adj[b - 1][a - 1] = true;
		}

		Queue q;

		for (int i = 0; i < n; i++) {

			if (visited[i])
				continue;

			q.push(i);
			visited[i] = true;

			while (!q.isEmpty()) {
				int cur = q.pop();

				for (int j = 0; j < n; j++) {
					if (adj[cur][j] && !visited[j])
					{
						visited[j] = true;
						q.push(j);
					}
				}
			}

			res++;
		}
		
		cout << '#' << tn << ' ' << res << '\n';
	}


	return 0;
}