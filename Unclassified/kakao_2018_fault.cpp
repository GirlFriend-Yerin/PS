#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int num;
	double fault;

};

bool cmp(const Node n1,const Node n2) {
	return n1.fault > n2.fault;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> counter(N + 2);
	vector<Node> vec(N + 1);

	for (auto stage : stages) {
		counter[stage]++;
	}

	int people = stages.size();

	for (int i = 0; i < N; i++) {
		vec[i].num = i + 1;
		vec[i].fault = counter[i + 1] / double(people);
		people -= counter[i + 1];
	}

	stable_sort(vec.begin(), vec.end() - 1, cmp);

	for (int i = 0; i < N; i++) {
		answer.push_back(vec[i].num);
	}

	return answer;
}

int main()
{
	int n, k; cin >> n >> k;
	vector<int> vec(k);

	for (int i = 0; i < k; i++)
		cin >> vec[i];

	vector<int> res = solution(n, vec);

	for (auto val : res) {
		cout << val << ' ';
	}

	return 0;
}