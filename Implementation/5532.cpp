#include <iostream>

using namespace std;

int main()
{
	int date; cin >> date;
	int korD, matD; cin >> korD >> matD;
	int korC, matC; cin >> korC >> matC;

	int ko = (korD / korC) + (korD % korC != 0);
	int ma = (matD / matC) + (matD % matC != 0);

	cout << date - (ko > ma ? ko : ma);

	return 0;
}