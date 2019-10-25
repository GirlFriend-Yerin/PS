#include <iostream>

using namespace std;

const int MAX = 5000;
const int sumMAX = 400000; // -200,000 ~ 200,000

int A[MAX];
bool visited[sumMAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int result = 0;

	//A + B + C = D
	//A + B = D - C

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//D - C 존재 여부
			if (visited[A[i] - A[j] + 200000])
			{
				result++;
				break;
			}
		}
		//A + B 표시
		for (int j = 0; j <= i; j++)
			visited[A[i] + A[j] + 200000] = true;
	}

	cout << result;

	return 0;

}