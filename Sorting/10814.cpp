#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Contact {
	int age;
	string name;

	bool operator<(const Contact& c2) const {
		return this->age < c2.age;
	}
};


int main()
{
	int n;

	scanf("%d", &n);

	vector<Contact> contacts(n);

	for (int i = 0; i < n; i++)
		cin >> contacts[i].age >> contacts[i].name;

	stable_sort(contacts.begin(), contacts.end());

	for (int i = 0; i < n; i++)
	{
		cout << contacts[i].age << ' ' << contacts[i].name << '\n';
	}

	return 0;
}