/*
	2019 01 15
	1049 기타줄
	Greedy Algorithm

	- 성공 -
*/

#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int minSixPieceOrPackage = 1001, minPiece = 1001;
	int cost = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int pack, piece;
		cin >> pack >> piece;

		if (minPiece > piece)
			minPiece = piece;

		pack = piece * 6 < pack ? piece * 6 : pack;

		if (minSixPieceOrPackage > pack)
			minSixPieceOrPackage = pack;
	}

	cost = (n / 6) * minSixPieceOrPackage;
	int remain = n % 6;
	
	if (remain)
	{
		if (minSixPieceOrPackage < (minPiece * remain))
			cost += minSixPieceOrPackage;
		else
			cost += remain * minPiece;
	}

	cout << cost;

	return 0;
}