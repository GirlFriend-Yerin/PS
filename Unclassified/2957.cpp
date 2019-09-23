#include <iostream>

using namespace std;

struct Node {
	int val;
	int cnt;
	Node* left;
	Node* right;

	Node() : cnt(0), left(nullptr), right(nullptr) {}
	Node(int val) : val(val), cnt(0), left(nullptr), right(nullptr) {};

	~Node() { 
		cout << "delete : " << val << '\n';
		delete left; 
		delete right; 
	}
};

void insert(Node* node,const int val) {
	node->cnt++;

	if (val < node->val) {
		if (node->left)
			insert(node->left, val);
		else
			node->left = new Node(val);
	}
	else {
		if (node->right)
			insert(node->right, val);
		else
			node->right = new Node(val);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	int root; cin >> root;

	Node* bst = nullptr;
	bst = new Node(root);

	for (int i = 0; i < n - 1; i++) {
		int val; cin >> val;
		insert(bst, val);
	}
	
	delete bst;

	return 0;
}