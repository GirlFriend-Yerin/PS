#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
class _vector {
private:
	int capacity;
	int pos;
	T* data;

public:
	_vector() : capacity(20), pos(0) { data = new T[capacity]; }
	_vector(int n) : capacity(n), pos(0) { data = new T[capacity]; }
	~_vector() { 
		if (data != NULL)
			delete[] data; 
		cout << "removed Vector" << '\n';
	}

	void push_back(T val) {
		if (pos == capacity) {
			int* temp = new T[capacity * 2];
			for (int i = 0; i < pos; i++) temp[i] = data[i];
			delete[] data;
			data = temp;
		}

		data[pos++] = val;
	}

	int size() { return pos; }
	T& operator [](int idx) { return data[idx];}
	void clear() { pos = 0; }
};

int _lower_bound(int arr[], int size, int value) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;

		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int _upper_bound(int arr[], int size, int value) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;

		if (arr[mid] <= value)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int _lower_bound(_vector<int>& arr, int size, int value) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;

		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int _upper_bound(_vector<int>& arr, int size, int value) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;

		if (arr[mid] <= value)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

struct Node {
	int key;
	int value;
	Node* next;
};

class HashTable {
private:
	int size;
	Node** table;

public:
	HashTable(int size) : size(size) { table = new Node*[size]; }

	int push()

};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	int arr[300] = {};
	_vector<int> _vec;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_vec.push_back(arr[i]);
		vec[i] = arr[i];
	}

	cout << "Lower\n";
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << _lower_bound(arr, n, i) << '\n';
	cout << "-----STL-----" << '\n';
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << lower_bound(arr, arr + n, i) - arr << '\n';

	cout << "\nUpper\n";
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : "  << _upper_bound(arr, n, i) << '\n';
	cout << "-----STL-----" << '\n';
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << upper_bound(arr, arr + n, i) - arr << '\n';

	cout << "Lower\n";
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << _lower_bound(_vec, n, i) << '\n';
	cout << "-----STL-----" << '\n';
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << lower_bound(vec.begin(), vec.end(), i) - vec.begin() << '\n';

	cout << "\nUpper\n";
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << _upper_bound(_vec, n, i) << '\n';
	cout << "-----STL-----" << '\n';
	for (int i = 0; i < 15; i++)
		cout << "MY : " << i << " : " << upper_bound(vec.begin(), vec.end(), i) - vec.begin() << '\n';

	return 0;
}