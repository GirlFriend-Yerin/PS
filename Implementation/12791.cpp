#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Album {
	int year;
	string name;

	Album() {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<Album> vec(25);

	vec[0].year = 1967; vec[0].name = "DavidBowie";
	vec[1].year = 1969; vec[1].name = "SpaceOddity";
	vec[2].year = 1970; vec[2].name = "TheManWhoSoldTheWorld";
	vec[3].year = 1971; vec[3].name = "HunkyDory";
	vec[4].year = 1972; vec[4].name = "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
	vec[5].year = 1973; vec[5].name = "AladdinSane";
	vec[6].year = 1973; vec[6].name = "PinUps";
	vec[7].year = 1974; vec[7].name = "DiamondDogs";
	vec[8].year = 1975; vec[8].name = "YoungAmericans";
	vec[9].year = 1976; vec[9].name = "StationToStation";
	vec[10].year = 1977; vec[10].name = "Low"; 
	vec[11].year = 1977; vec[11].name = "Heroes";
	vec[12].year = 1979; vec[12].name = "Lodger";
	vec[13].year = 1980; vec[13].name = "ScaryMonstersAndSuperCreeps";
	vec[14].year = 1983; vec[14].name = "LetsDance";
	vec[15].year = 1984; vec[15].name = "Tonight";
	vec[16].year = 1987; vec[16].name = "NeverLetMeDown";
	vec[17].year = 1993; vec[17].name = "BlackTieWhiteNoise";
	vec[18].year = 1995; vec[18].name = "1.Outside";
	vec[19].year = 1997; vec[19].name = "Earthling";
	vec[20].year = 1999; vec[20].name = "Hours";
	vec[21].year = 2002; vec[21].name = "Heathen";
	vec[22].year = 2003; vec[22].name = "Reality";
	vec[23].year = 2013; vec[23].name = "TheNextDay";
	vec[24].year = 2016; vec[24].name = "BlackStar";


	for (int i = 0; i < n; i++) {
		int to, des; cin >> to >> des;

		vector<Album> res;

		for (int j = 0; j < vec.size(); j++)
			if (to <= vec[j].year && vec[j].year <= des)
				res.push_back(vec[j]);

		cout << res.size() << '\n';
		for (Album item : res)
			cout << item.year << ' ' << item.name << '\n';

	}

	return 0;
}