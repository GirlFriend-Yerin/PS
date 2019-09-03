#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

struct Node {
	string value;
	Node* next;
	Node* pre;

	Node() : pre(nullptr), next(nullptr) {}
	Node(string& str) : value(str), pre(nullptr), next(nullptr) {}

	~Node() { delete next; }
};

int nodeCnt;
Node* head;

void _insert(string& value) {

	Node* cursor = head;
	Node* item = new Node(value);

	if (head->next != nullptr) {
		head->next->pre = item;
		item->pre = head;
		item->next = head->next;
	}
	head->next = item;
	nodeCnt++;
}

int _update(string& value, const int cacheSize) {

	Node* cursor = head->next;
	Node* pre = head;

	while (cursor != nullptr) {
		if (cursor->value == value) {
			pre->next = cursor->next;
			if (pre->next != nullptr)
				pre->next->pre = pre;
			cursor->next = head->next;
			cursor->next->pre = cursor;
			cursor->pre = head;
			head->next = cursor;
			
			return 1;
		}
		pre = cursor;
		cursor = cursor->next;
	}

	_insert(value);
	if (nodeCnt > cacheSize) {
		pre->pre->next = nullptr;
		delete pre;
		nodeCnt--;
	}

	return 5;
}

int _min(const int a, const int b) { return b ^ ((a ^b) & -(a < b)); }

void toLower(string& str) {
	for (auto& ch : str) 
		ch += ('A' <= ch && ch <= 'Z') ? 'a' - 'A' : 0;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = cacheSize ? 0 : 5 * cities.size();

	vector<string> lru;

	if (cacheSize != 0) {
		for (auto city : cities) {
			toLower(city);

			auto iter = find(lru.begin(), lru.end(), city);

			if (iter != lru.end()) {
				answer++;
				lru.erase(iter);
			}
			else {
				answer += 5;
				if (cacheSize == lru.size())
					lru.erase(lru.end());
			}
		}
	}

	return answer;
}

int main()
{
	int n, c; cin >> n >> c;
	vector<string> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	cout << solution(c, vec);

	return 0;
}