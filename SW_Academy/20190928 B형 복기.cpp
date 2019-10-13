#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000;

void swap5(int n, int origin[], int target[]) {
	// 제공되는 함수
}

typedef pair<int, int> pii;

/*
	해결전략
	0번 위치에는 0이 와야한다.
	따라서 i의 값은 i로 가야하며 이를 해결하기 위해 위치를 따라가면 결국 사이클이 형성된다.
	이 사이클을 전부 구한 후 길이에 따라 다른 함수를 호출한다.

	ex
	0 5 3 2 1 4
	0번 위치에는 0이 있으니 체인을 만들 필요가 없다.
	1번 위치에는 5가 있고 5번 에는 4가 있다.
	4위치에는 1이 있다.
	따라서 1(5) -> 5(4) -> 4(1) -> 1(5) 라는 체인이 형성된다. < 위치(위치의 값) >
	3 과 2 도 2(3) -> 3(2) -> 3(2) 체인이 형성된다.
	이 체인이 제자리로 가기 위해서는 현재 있는 위치에서 다음으로 갈 위치로 이동하면 된다.
	5 4 1 체인은 origin > 1 5 4 / target > 5 4 1 로 이동하면 각자의 위치로 갈 수 있다.
*/

vector<int> makeChain(const vector<pii>& vec,bool visited[MAXN], int start)
{
	vector<int> res;

	while (!visited[start]) {
		res.push_back(start);
		visited[start] = true;
	}

	return res;
}

void call5(vector<int>& vec, int pos) {
	int origin[] = { vec[pos], vec[pos + 1], vec[pos + 2], vec[pos + 3], vec[pos + 4] };
	int target[] = { vec[pos + 1], vec[pos + 2], vec[pos + 3], vec[pos + 4], vec[pos] };

	swap5(5, origin, target);
}

void call4(vector<int>& vec, int pos) {
	int origin[] = { vec[pos], vec[pos + 1], vec[pos + 2], vec[pos + 3] };
	int target[] = { vec[pos + 1], vec[pos + 2], vec[pos + 3], vec[pos] };

	swap5(4, origin, target);
}

void call3(vector<int>& vec, int pos) {
	int origin[] = { vec[pos], vec[pos + 1], vec[pos + 2]};
	int target[] = { vec[pos + 1], vec[pos + 2], vec[pos]};

	swap5(3, origin, target);
}

void call2(vector<int>& vec, int pos) {
	int origin[] = { vec[pos], vec[pos + 1],};
	int target[] = { vec[pos + 1], vec[pos] };

	swap5(2, origin, target);
}

void api(int n, int box[MAXN]) {

	bool visited[MAXN]; // 방문 처리 변수
	for (int i = 0; i < n; i++) visited[i] = false;

	// 체인을 만들기 위한 벡터
	vector<pii> vec(n);

	// 연결관계를 Pair로 저장
	for (int i = 0; i < n; i++) {
		vec[i].first = i;
		vec[i].second = box[i];
	}

	vector<vector<vector<int>>> chains(5); // 2개, 3개, 4개, 5개, 6개 이상

	// Chain 제작
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int> chain = makeChain(vec, visited, i);
			int chainSize = chain.size();

			// chain 저장
			chains[chainSize - 2].push_back(chain);
		}
	}

	// 6개 이상 처리 알고리즘
	for (int i = 0; i < chains[4].size(); i++)
	{
		int len = chains[4][i].size();
		int pos = 0;
		while (pos + 5 < len) {
			call5(chains[4][i], pos);
			pos += 4;
		}

		switch (len - pos) {
		case 2: call2(chains[4][i], pos); break;
		case 3: call3(chains[4][i], pos); break;
		case 4: call4(chains[4][i], pos); break;
		case 5: call5(chains[4][i], pos); break;
		}
	}

	// 5개 처리 알고리즘
	for (int i = 0; i < chains[3].size(); i++)
		call5(chains[3][i], 0);

	// 4개 처리 알고리즘
	for (int i = 0; i < chains[2].size(); i++)
		call4(chains[3][i], 0);

	// 2 + 3 처리 알고리즘
	int thr = chains[1].size();
	int two = chains[0].size();
	int p_thr = 0;
	int p_two = 0;

	while (p_thr < thr && p_two < two) {
		int origin[] = { chains[0][p_two][0], chains[0][p_two][1], chains[1][p_thr][0], chains[1][p_thr][1], chains[1][p_thr][2] };
		int target[] = { chains[0][p_two][1], chains[0][p_two][0], chains[1][p_thr][2], chains[1][p_thr][1], chains[1][p_thr][0] };

		swap5(5, origin, target);
		p_thr++; p_two++;
	}

	// 3 처리 알고리즘
	while (p_thr < thr) {
		call3(chains[1][p_thr], 0);
		p_thr++;
	}

	// 2 + 2 처리 알고리즘
	while (p_two + 1< two) {
		int origin[] = { chains[0][p_two][0], chains[0][p_two][1], chains[0][p_two+1][0], chains[0][p_two+1][1] };
		int target[] = { chains[0][p_two][1], chains[0][p_two][0], chains[0][p_two+1][1], chains[0][p_two+1][0] };

		swap5(4, origin, target);
		p_two += 2;
	}

	// 2 처리 알고리즘

	while (p_two < two){
		call2(chains[0][p_two], 0);
		p_two++;
	}
}