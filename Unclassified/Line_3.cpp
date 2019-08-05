#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int id;
	string data1;
	string data2;

	Data() {};
	Data(int i, string d1, string d2) : id(i), data1(d1), data2(d2) {};
};


bool mCmp(Data& d1, Data& d2) {
	return d1.id < d2.id;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string columns[2][2];
	vector<Data> table[2];
	int tableCount[2];

	for (int i = 0; i < 2; i++)
	{
		int rowCount, colCount = 2;
		int startPos = 0;
		string input;

		cin >> rowCount;
		cin >> input >> columns[i][0] >> input;

		rowCount--;

		tableCount[i] = rowCount;
		table[i].resize(rowCount);

		if ('0' <= input[0] && input[0] <= '9')
		{
			string last;
			cin >> last;
			table[i][startPos++] = Data(stoi(input), last, "");
		}
		else
		{
			columns[i][1] = input;
			colCount++;
		}

		for (int j = startPos; j < rowCount; j++)
		{
			string data[3];

			for (int k = 0; k < colCount; k++)
				cin >> data[k];

			table[i][j] = Data(stoi(data[0]), data[1], data[2]);
		}

		sort(table[i].begin(), table[i].end(), mCmp);
	}

	cout << "id ";
	for (int i = 0; i < 2; i++)
		cout << columns[i][0] << ' ' << columns[i][1] << ' ';
	cout << '\n';

	int leftPivot = 0, rightPivot = 0;
	while (leftPivot < tableCount[0] && rightPivot < tableCount[1])
	{
		Data left = table[0][leftPivot], right = table[1][rightPivot];

		if (left.id == right.id)
		{
			cout << left.id << ' ' << left.data1 << ' ' << left.data2 << ' ';
			cout << right.data1 << ' ' << right.data2 << '\n';
			leftPivot++; rightPivot++;
		}
		else
		{
			if (table[0][leftPivot].id < table[1][rightPivot].id)
			{
				cout << left.id << ' ' << left.data1 << ' ' << left.data2 << " NULL NULL\n";
				leftPivot++;
			}
			else
				rightPivot++;
		}
	}

	return 0;
}