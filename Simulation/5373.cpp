#include <iostream>

using namespace std;

const short FACE = 6;
const short SIDE = 3;

// 0 - À§, 1 - ¹Ù´Ú, 2 - ¾Õ, 3 - µÚ, 4 - ¿Ş , 5 - ¿À
// 0 - w , 1 - y , 2 - r, 3 - o, 4 - g , 5 - b

void faceRotate(char cube[FACE][SIDE][SIDE], int faceNum, bool left) {
	if (left) {
		char temp = cube[faceNum][0][0];

		cube[faceNum][0][0] = cube[faceNum][0][2];
		cube[faceNum][0][2] = cube[faceNum][2][2];
		cube[faceNum][2][2] = cube[faceNum][2][0];
		cube[faceNum][2][0] = temp;

		temp = cube[faceNum][0][1];
		cube[faceNum][0][1] = cube[faceNum][1][2];
		cube[faceNum][1][2] = cube[faceNum][2][1];
		cube[faceNum][2][1] = cube[faceNum][1][0];
		cube[faceNum][1][0] = temp;
	}
	else
	{
		char temp = cube[faceNum][0][0];

		cube[faceNum][0][0] = cube[faceNum][2][0];
		cube[faceNum][2][0] = cube[faceNum][2][2];
		cube[faceNum][2][2] = cube[faceNum][0][2];
		cube[faceNum][0][2] = temp;

		temp = cube[faceNum][0][1];
		cube[faceNum][0][1] = cube[faceNum][1][0];
		cube[faceNum][1][0] = cube[faceNum][2][1];
		cube[faceNum][2][1] = cube[faceNum][1][2];
		cube[faceNum][1][2] = temp;
	}
}

void rotate(char cube[FACE][SIDE][SIDE], char face, bool up) {

	if (face == 'U')
	{
		faceRotate(cube, 0, up);
		if (up) {

			char temp[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };

			cube[2][0][0] = cube[4][0][0];
			cube[2][0][1] = cube[4][0][1];
			cube[2][0][2] = cube[4][0][2];

			cube[4][0][0] = cube[3][0][0];
			cube[4][0][1] = cube[3][0][1];
			cube[4][0][2] = cube[3][0][2];

			cube[3][0][0] = cube[5][0][0];
			cube[3][0][1] = cube[5][0][1];
			cube[3][0][2] = cube[5][0][2];

			cube[5][0][0] = temp[0];
			cube[5][0][1] = temp[1];
			cube[5][0][2] = temp[2];

		}
		else
		{
			char temp[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };

			cube[2][0][0] = cube[5][0][0];
			cube[2][0][1] = cube[5][0][1];
			cube[2][0][2] = cube[5][0][2];

			cube[5][0][0] = cube[3][0][0];
			cube[5][0][1] = cube[3][0][1];
			cube[5][0][2] = cube[3][0][2];

			cube[3][0][0] = cube[4][0][0];
			cube[3][0][1] = cube[4][0][1];
			cube[3][0][2] = cube[4][0][2];

			cube[4][0][0] = temp[0];
			cube[4][0][1] = temp[1];
			cube[4][0][2] = temp[2];
		}
	}
	else if (face == 'D')
	{
		faceRotate(cube, 1, up);
		if (up) {

			char temp[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };

			cube[2][2][0] = cube[5][2][0];
			cube[2][2][1] = cube[5][2][1];
			cube[2][2][2] = cube[5][2][2];

			cube[5][2][0] = cube[3][2][0];
			cube[5][2][1] = cube[3][2][1];
			cube[5][2][2] = cube[3][2][2];

			cube[3][2][0] = cube[4][2][0];
			cube[3][2][1] = cube[4][2][1];
			cube[3][2][2] = cube[4][2][2];

			cube[4][2][0] = temp[0];
			cube[4][2][1] = temp[1];
			cube[4][2][2] = temp[2];

		}
		else
		{
			char temp[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };

			cube[2][2][0] = cube[4][2][0];
			cube[2][2][1] = cube[4][2][1];
			cube[2][2][2] = cube[4][2][2];

			cube[4][2][0] = cube[3][2][0];
			cube[4][2][1] = cube[3][2][1];
			cube[4][2][2] = cube[3][2][2];

			cube[3][2][0] = cube[5][2][0];
			cube[3][2][1] = cube[5][2][1];
			cube[3][2][2] = cube[5][2][2];

			cube[5][2][0] = temp[0];
			cube[5][2][1] = temp[1];
			cube[5][2][2] = temp[2];
		}
	}
	else if (face == 'F')
	{
		faceRotate(cube, 2, up);
		if (up) {

			char temp[3] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };

			cube[0][2][0] = cube[5][0][0];
			cube[0][2][1] = cube[5][1][0];
			cube[0][2][2] = cube[5][2][0];

			cube[5][0][0] = cube[1][0][0];
			cube[5][1][0] = cube[1][0][1];
			cube[5][2][0] = cube[1][0][2];

			cube[1][0][0] = cube[4][0][2];
			cube[1][0][1] = cube[4][1][2];
			cube[1][0][2] = cube[4][2][2];

			cube[4][0][2] = temp[0];
			cube[4][1][2] = temp[1];
			cube[4][2][2] = temp[2];
		}
		else
		{
			char temp[3] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };

			cube[0][2][0] = cube[4][2][2];
			cube[0][2][1] = cube[4][1][2];
			cube[0][2][2] = cube[4][0][2];

			cube[4][2][2] = cube[1][0][0];
			cube[4][1][2] = cube[1][0][1];
			cube[4][0][2] = cube[1][0][2];

			cube[1][0][0] = cube[5][2][0];
			cube[1][0][1] = cube[5][1][0];
			cube[1][0][2] = cube[5][0][0];

			cube[5][2][0] = temp[0];
			cube[5][1][0] = temp[1];
			cube[5][0][0] = temp[2];
		}
	}
	else if (face == 'B')
	{
		faceRotate(cube, 3, up);
		if (up) {

			char temp[3] = { cube[0][0][0], cube[0][0][1], cube[0][0][2] };

			cube[0][0][0] = cube[4][2][0];
			cube[0][0][1] = cube[4][1][0];
			cube[0][0][2] = cube[4][0][0];

			cube[4][2][0] = cube[1][0][2];
			cube[4][1][0] = cube[1][0][1];
			cube[4][0][0] = cube[1][0][0];

			cube[1][0][2] = cube[5][0][2];
			cube[1][0][1] = cube[5][1][2];
			cube[1][0][0] = cube[5][2][2];

			cube[5][0][2] = temp[0];
			cube[5][1][2] = temp[1];
			cube[5][2][2] = temp[2];
		}
		else
		{
			char temp[3] = { cube[0][0][0], cube[0][0][1], cube[0][0][2] };

			cube[0][0][0] = cube[5][0][2];
			cube[0][0][1] = cube[5][1][2];
			cube[0][0][2] = cube[5][2][2];

			cube[5][0][2] = cube[1][2][2];
			cube[5][1][2] = cube[1][2][1];
			cube[5][2][2] = cube[1][2][0];

			cube[1][2][2] = cube[4][2][0];
			cube[1][2][1] = cube[4][1][0];
			cube[1][2][0] = cube[4][0][0];

			cube[4][2][0] = temp[0];
			cube[4][1][0] = temp[1];
			cube[4][0][0] = temp[2];
		}
	}
	else if (face == 'L')
	{
		faceRotate(cube, 4, up);
		if (up) {
			char temp[3] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };

			cube[0][0][0] = cube[2][0][0];
			cube[0][1][0] = cube[2][1][0];
			cube[0][2][0] = cube[2][2][0];

			cube[2][0][0] = cube[1][0][0];
			cube[2][1][0] = cube[1][1][0];
			cube[2][2][0] = cube[1][2][0];

			cube[1][0][0] = cube[3][0][2];
			cube[1][1][0] = cube[3][1][2];
			cube[1][2][0] = cube[3][2][2];

			cube[3][0][2] = temp[0];
			cube[3][1][2] = temp[1];
			cube[3][2][2] = temp[2];
		}
		else
		{
			char temp[3] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };

			cube[0][0][0] = cube[3][2][2];
			cube[0][1][0] = cube[3][1][2];
			cube[0][2][0] = cube[3][0][2];

			cube[3][2][2] = cube[1][2][0];
			cube[3][1][2] = cube[1][1][0];
			cube[3][0][2] = cube[1][0][0];

			cube[1][2][0] = cube[2][0][0];
			cube[1][1][0] = cube[2][1][0];
			cube[1][0][0] = cube[2][2][0];

			cube[2][0][0] = temp[0];
			cube[2][1][0] = temp[1];
			cube[2][2][0] = temp[2];
		}
	}
	else if (face == 'R')
	{
		faceRotate(cube, 5, up);

		if (up) {
			char temp[3] = { cube[0][0][2], cube[0][1][2], cube[0][2][2] };

			cube[0][0][2] = cube[3][2][0];
			cube[0][1][2] = cube[3][1][0];
			cube[0][2][2] = cube[3][0][0];

			cube[3][2][0] = cube[1][0][2];
			cube[3][1][0] = cube[1][1][2];
			cube[3][0][0] = cube[1][2][2];

			cube[1][0][2] = cube[2][0][2];
			cube[1][1][2] = cube[2][1][2];
			cube[1][2][2] = cube[2][2][2];

			cube[2][0][2] = temp[0];
			cube[2][1][2] = temp[1];
			cube[2][2][2] = temp[2];
		}
		else
		{
			char temps[3] = { cube[0][0][2], cube[0][1][2], cube[0][2][2] };

			cube[0][0][2] = cube[2][0][2];
			cube[0][1][2] = cube[2][1][2];
			cube[0][2][2] = cube[2][2][2];

			cube[2][0][2] = cube[1][0][2];
			cube[2][1][2] = cube[1][1][2];
			cube[2][2][2] = cube[1][2][2];

			cube[1][0][2] = cube[3][0][0];
			cube[1][1][2] = cube[3][1][0];
			cube[1][2][2] = cube[3][2][0];

			cube[3][0][0] = temps[0];
			cube[3][1][0] = temps[1];
			cube[3][2][0] = temps[2];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	while (tcc--)
	{
		char cube[FACE][SIDE][SIDE] = {
		{ {'w','w','w'}, {'w','w','w'}, {'w','w','w'} },
		{ {'y','y','y'}, {'y','y','y'}, {'y','y','y'} },
		{ {'r','r','r'}, {'r','r','r'}, {'r','r','r'} },
		{ {'o','o','o'}, {'o','o','o'}, {'o','o','o'} },
		{ {'g','g','g'}, {'g','g','g'}, {'g','g','g'} },
		{ {'b','b','b'}, {'b','b','b'}, {'b','b','b'} } };

		int count; cin >> count;

		while (count--) {
			char input[3]; cin >> input;

			rotate(cube, input[0], input[1] == '-' ? true : false);

			/*for (int i = 0; i < SIDE; i++)
			{
				for (int j = 0; j < SIDE; j++)
					cout << cube[0][i][j];
				cout << '\n';
			}
			cout << endl;*/
		}

		for (int i = 0; i < SIDE; i++)
		{
			for (int j = 0; j < SIDE; j++)
				cout << cube[0][i][j];
			cout << '\n';
		}
	}

	return 0;
}