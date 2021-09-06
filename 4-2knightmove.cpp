#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, L;
int map[501][501];
int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
queue<pair<int, int> > q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(map, -1, sizeof(map));
		int x1, y1, x2, y2;

		cin >> L;

		cin >> x1 >> y1 >> x2 >> y2;

		q.push({ x1, y1 });
		map[x1][y1] = 0;

		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;

			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (0 <= nx && nx < L && 0 <= ny && ny < L && map[nx][ny] == -1) {
					map[nx][ny] = map[curx][cury] + 1;
					q.push({ nx, ny });
				}
			}
		}
		cout << map[x2][y2] << "\n";
	}

	return 0;
}