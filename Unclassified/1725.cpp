#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> height(N + 1);

	for (int i = 0; i < N; i++) cin >> height[i];

	//���� �� ��Ÿ�� ���̰� i��° ��Ÿ�� ���̺��� �۾ƾ� ������ ������
	stack<int> remaining;

	int result = 0;

	for (int i = 0; i < height.size(); i++)
	{
		//�����ִ� ���ڵ� �� ������ �� ���ڰ� height[i]���� ���ٸ�
		//�� ������ �ִ� �簢���� i���� ������

		while (!remaining.empty() && height[remaining.top()] >= height[i])
		{
			int idx = remaining.top();
			remaining.pop();

			int width = remaining.empty() ? i : (i - remaining.top() - 1);

			result = max(result, height[idx] * width);
		}
		remaining.push(i); //���ÿ� ����ִ´�
	}

	cout << result << "\n";

	return 0;
}