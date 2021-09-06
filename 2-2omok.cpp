#include <iostream>
#include <cstring>

using namespace std;

int T;
int omok[16][16];
bool finish;
char winner;

int chk(int x, int y, int color, int newx, int newy) {
	if (x == 0 || y == 0 || x == 16 || y == 16) return 0;
	if (omok[x][y] == color)
		return chk(x + newx, y + newy, color, newx, newy) + 1;
	else return 0;
}

int win(int x, int y, int color) {
	int upleft = chk(x, y, color, -1, -1);
	int downright = chk(x, y, color, 1, 1);
	if (upleft + downright - 1 == 5) return 1;

	int up = chk(x, y, color, 0, -1);
	int down = chk(x, y, color, 0, 1);
	if (up + down - 1 == 5) return 1;

	int upright = chk(x, y, color, 1, -1);
	int downleft = chk(x, y, color, -1, 1);
	if (upright + downleft - 1 == 5) return 1;

	int right = chk(x, y, color, 1, 0);
	int left = chk(x, y, color, -1, 0);
	if (right + left - 1 == 5) return 1;


	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(omok, 0, sizeof(omok));
		finish = false;

		int Case = 1;

		for (int i = 0; i < 225; i++) {
			int x, y;
			cin >> x >> y;

			if (Case % 2 == 1) omok[x][y] = 1;
			else omok[x][y] = 2;

			if (!finish) {
				if (win(x, y, 1) != 0) {
					finish = true;
					cout << Case << " B\n";
				}
				else if (win(x, y, 2) != 0) {
					finish = true;
					cout << Case << " W\n";
				}
			}
			Case++;
		}
	}

	return 0;
}