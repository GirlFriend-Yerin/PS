#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Poker {
	int val;
	bool color;

	Poker() {};
	Poker(int v, bool c) : val(v), color(c) {};
};
struct PokerPair {
	Poker p1;
	Poker p2;
	bool cot = false;
	bool sameV = false;
	bool sameC = false;
	bool biggerIsB = false;
	int biggerV;
	int smallV;

	PokerPair() {};
	PokerPair(Poker p1, Poker p2) : p1(p1), p2(p2) {
		int p1V = p1.val, p2V = p2.val;

		if (p1V + 1 == p2V || p1V - 1 == p2V)
			cot = true;
		else if ((p1V == 15 && p2V == 1) || (p1V == 1 && p2V == 15))
			cot = true;

		if (p1V == p2V)
			sameV = true;

		if (p1.color == p2.color)
			sameC = true;

		biggerV = p1V < p2V ? p2V : p1V;
		smallV = p1V < p2V ? p1V : p2V;

		if (biggerV == p1.val)
			biggerIsB = p1.color;
		else
			biggerIsB = p2.color;
	};
};

vector<Poker> cards;
vector<PokerPair> cardsPair;

bool subCmp(PokerPair& pp1, PokerPair& pp2)
{
	if (pp1.sameC && !pp2.sameC)
		return true;
	else if (!pp1.sameC && pp2.sameC)
		return false;

	if (pp1.biggerV > pp2.biggerV)
		return true;
	else if (pp1.biggerV < pp2.biggerV)
		return false;

	if (pp1.smallV > pp2.smallV)
		return true;
	else if (pp1.smallV < pp2.smallV)
		return false;

	return pp1.biggerIsB;
}

bool cmp(PokerPair& pp1, PokerPair& pp2) {

	if (pp1.cot && pp2.cot)
		return subCmp(pp1, pp2);
	else if (pp1.cot && !pp2.cot)
		return true;
	else if (!pp1.cot && pp2.cot)
		return false;

	if (pp1.sameV && pp2.sameV)
		return subCmp(pp1, pp2);
	else if (pp1.sameV && !pp2.sameV)
		return true;
	else if (!pp1.sameV && pp2.sameV)
		return false;

	return subCmp(pp1, pp2);
}

int main()
{
	string input; cin >> input;

	int cardCount = ((input.length() - 2) / 3) + 1;

	for (int i = 0; i < input.length() + 1; i += 3) {
		char v = input[i], c = input[i + 1];
		int val;

		if ('a' <= v && v <= 'f')
			val = v - 'a' + 10;
		else
			val = v - '0';

		if (c == 'b')
			cards.push_back(Poker(val, true));
		else
			cards.push_back(Poker(val, false));
	}

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 6; j++)
			cardsPair.push_back(PokerPair(cards[i], cards[j]));

	sort(cardsPair.begin(), cardsPair.end(), cmp);

	for (int i = 0; i < cardsPair.size(); i++) {
		Poker p1 = cardsPair[i].p1, p2 = cardsPair[i].p2;

		if (cardsPair[i].p1.val < 10)
			cout << cardsPair[i].p1.val;
		else
			cout << char(cardsPair[i].p1.val - 10 + 'a');

		cout << (cardsPair[i].p1.color ? 'b' : 'w');

		if (cardsPair[i].p2.val < 10)
			cout << cardsPair[i].p2.val;
		else
			cout << char(cardsPair[i].p2.val - 10 + 'a');

		cout << (cardsPair[i].p2.color ? 'b' : 'w') << '\n';
	}


	return 0;
}