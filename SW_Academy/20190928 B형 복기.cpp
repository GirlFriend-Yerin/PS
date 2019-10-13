#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000;

void swap5(int n, int origin[], int target[]) {
	// �����Ǵ� �Լ�
}

typedef pair<int, int> pii;

/*
	�ذ�����
	0�� ��ġ���� 0�� �;��Ѵ�.
	���� i�� ���� i�� �����ϸ� �̸� �ذ��ϱ� ���� ��ġ�� ���󰡸� �ᱹ ����Ŭ�� �����ȴ�.
	�� ����Ŭ�� ���� ���� �� ���̿� ���� �ٸ� �Լ��� ȣ���Ѵ�.

	ex
	0 5 3 2 1 4
	0�� ��ġ���� 0�� ������ ü���� ���� �ʿ䰡 ����.
	1�� ��ġ���� 5�� �ְ� 5�� ���� 4�� �ִ�.
	4��ġ���� 1�� �ִ�.
	���� 1(5) -> 5(4) -> 4(1) -> 1(5) ��� ü���� �����ȴ�. < ��ġ(��ġ�� ��) >
	3 �� 2 �� 2(3) -> 3(2) -> 3(2) ü���� �����ȴ�.
	�� ü���� ���ڸ��� ���� ���ؼ��� ���� �ִ� ��ġ���� �������� �� ��ġ�� �̵��ϸ� �ȴ�.
	5 4 1 ü���� origin > 1 5 4 / target > 5 4 1 �� �̵��ϸ� ������ ��ġ�� �� �� �ִ�.
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

	bool visited[MAXN]; // �湮 ó�� ����
	for (int i = 0; i < n; i++) visited[i] = false;

	// ü���� ����� ���� ����
	vector<pii> vec(n);

	// ������踦 Pair�� ����
	for (int i = 0; i < n; i++) {
		vec[i].first = i;
		vec[i].second = box[i];
	}

	vector<vector<vector<int>>> chains(5); // 2��, 3��, 4��, 5��, 6�� �̻�

	// Chain ����
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int> chain = makeChain(vec, visited, i);
			int chainSize = chain.size();

			// chain ����
			chains[chainSize - 2].push_back(chain);
		}
	}

	// 6�� �̻� ó�� �˰���
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

	// 5�� ó�� �˰���
	for (int i = 0; i < chains[3].size(); i++)
		call5(chains[3][i], 0);

	// 4�� ó�� �˰���
	for (int i = 0; i < chains[2].size(); i++)
		call4(chains[3][i], 0);

	// 2 + 3 ó�� �˰���
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

	// 3 ó�� �˰���
	while (p_thr < thr) {
		call3(chains[1][p_thr], 0);
		p_thr++;
	}

	// 2 + 2 ó�� �˰���
	while (p_two + 1< two) {
		int origin[] = { chains[0][p_two][0], chains[0][p_two][1], chains[0][p_two+1][0], chains[0][p_two+1][1] };
		int target[] = { chains[0][p_two][1], chains[0][p_two][0], chains[0][p_two+1][1], chains[0][p_two+1][0] };

		swap5(4, origin, target);
		p_two += 2;
	}

	// 2 ó�� �˰���

	while (p_two < two){
		call2(chains[0][p_two], 0);
		p_two++;
	}
}