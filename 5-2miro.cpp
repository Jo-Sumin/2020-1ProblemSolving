#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int T, N, M;
char map[21][21];
bool chk[1 << 6][21][21];
p dir[] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
int kcnt;

int bfs(int y, int x) {
	queue<pair<p, p> > q;
	q.push({ {y, x}, {0, 0} });

	while (!q.empty()) {
		int curx = q.front().first.second;
		int cury = q.front().first.first;
		int cnt = q.front().second.first;
		int key = q.front().second.second;

		q.pop();

		if (kcnt == key) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = curx + dir[i].second;
			int ny = cury + dir[i].first;

			if (0 <= ny && ny <= N && 0 <= nx && nx <= M && !chk[key][ny][nx] && map[ny][nx] != '#') {
				if (map[ny][nx] == '*' || map[ny][nx] == '@') {
					chk[key][ny][nx] = true;
					q.push({ {ny, nx}, {cnt + 1, key} });
				}
				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
					int nkey = key | 1 << (int(map[ny][nx] - 'a'));

					if (!chk[nkey][ny][nx]) {
						chk[key][ny][nx] = true;
						chk[nkey][ny][nx] = true;
						q.push({ {ny, nx}, {cnt + 1, nkey} });
					}
				}

				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
					if (key & 1 << (int(map[ny][nx] - 'A'))) {
						chk[key][ny][nx] = true;
						q.push({ {ny, nx}, {cnt + 1, key} });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		kcnt = 0;

		cin >> N >> M;

		p start;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];

				if (map[i][j] >= 'a' && map[i][j] <= 'f')
					kcnt |= 1 << int(map[i][j] - 'a');
				else if (map[i][j] == '@') {
					start.first = i; start.second = j;
				}
			}
		}
		cout << bfs(start.first, start.second) << "\n";
	}

	return 0;
}