#include <iostream>

using namespace std;

const int MAX = 10'0000;

struct Node {
	Node* pre;
	Node* next;
	char val;

	Node() : pre(nullptr), next(nullptr) {}
	Node(char v) : pre(nullptr), next(nullptr), val(v) {}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	Node* cursor;
	int cnt;

public:
	LinkedList() : cnt(0) {
		head = new Node(-1);
		tail = new Node(-1);
		cursor = new Node(0);

		head->next = tail;
		tail->pre = head;
		cursor->pre = head;
		cursor->next = tail;
	};

	~LinkedList() {
		Node* node = head->next;
		delete head;
		while (node != tail)
		{
			node = node->next;
			delete node->pre;
		}
		delete node;

	}

	void add(char v) {
		Node* ppre = cursor->pre;
		Node* newNode = new Node(v);

		newNode->pre = cursor->pre;
		newNode->next = cursor->next;

		cursor->pre->next = newNode;
		cursor->next->pre = newNode;
		cursor->pre = newNode;

		cnt++;
	}

	void moveLeft() {
		if (cursor->pre != head)
		{
			cursor->next = cursor->pre;
			cursor->pre = cursor->pre->pre;
		}
	}

	void modeRight() {
		if (cursor->next != tail) {
			cursor->pre = cursor->next;
			cursor->next = cursor->next->next;
		}
	}

	void remove() {
		if (cursor->pre != head) {
			Node* node = cursor->pre;

			cursor->pre->pre->next = cursor->next;
			cursor->next->pre = cursor->pre->pre;
			cursor->pre = cursor->pre->pre;

			cnt--;

			delete node;
		}
	}

	void print() {
		Node* pos = head->next;

		while (pos != tail)
		{
			cout << pos->val;
			pos = pos->next;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LinkedList linkedList;
	char input[MAX + 1] = {}; cin >> input;

	int n; cin >> n;

	for (int i = 0; input[i]; i++) linkedList.add(input[i]);

	while (n--) {
		char order; cin >> order;

		switch (order) {
		case 'L':
			linkedList.moveLeft();
			break;
		case 'D':
			linkedList.modeRight();
			break;
		case 'B':
			linkedList.remove();
			break;
		case 'P':
			char val; cin >> val;
			linkedList.add(val);
			break;
		}
		//linkedList.print();
	}

	linkedList.print();

	return 0;
}