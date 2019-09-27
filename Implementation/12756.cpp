#include <iostream>

using namespace std;

int main()
{
	int aa, al, ba, bl; cin >> aa >> al >> ba >> bl;

	int blaa = bl / aa + !!(bl%aa);
	int alba = al / ba + !!(al%ba);
	
	cout << ( blaa != alba ? (blaa > alba ? "PLAYER B" : "PLAYER A") : "DRAW");

	return 0;
}