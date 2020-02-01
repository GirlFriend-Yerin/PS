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

	//제일 끝 울타리 높이가 i번째 울타리 높이보다 작아야 범위가 설정됨
	stack<int> remaining;

	int result = 0;

	for (int i = 0; i < height.size(); i++)
	{
		//남아있는 판자들 중 오른쪽 끝 판자가 height[i]보다 높다면
		//이 판자의 최대 사각형은 i에서 끝난다

		while (!remaining.empty() && height[remaining.top()] >= height[i])
		{
			int idx = remaining.top();
			remaining.pop();

			int width = remaining.empty() ? i : (i - remaining.top() - 1);

			result = max(result, height[idx] * width);
		}
		remaining.push(i); //스택에 집어넣는다
	}

	cout << result << "\n";

	return 0;
}