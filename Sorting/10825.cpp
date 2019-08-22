#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
	string name;
	int kor;
	int eng;
	int mat;

	bool operator<(const Student& s) {
		if (kor < s.kor)
			return false;
		else if (kor == s.kor)
		{
			if (eng > s.eng)
				return false;
			else if (eng == s.eng)
			{
				if (mat < s.mat)
					return false;
				else if (mat == s.mat)
				{
					if (name > s.name)
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	int n;

	cin >> n;

	vector<Student> student(n);

	for (int i = 0; i < n; i++)
		cin >> student[i].name >> student[i].kor >> student[i].eng >> student[i].mat;

	sort(student.begin(), student.end());

	for (int i = 0; i < n; i++)
		printf("%s\n", student[i].name.c_str());

	return 0;
}