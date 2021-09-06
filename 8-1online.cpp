#include <iostream>
#include <cstring>

using namespace std;

int T, M, N;

int slot[101];
int score[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(slot, 0, sizeof(slot));
		memset(score, 0, sizeof(score));
		int ans = 0;

		cin >> M >> N;

		for (int i = 1; i <= M; i++) {
			cin >> score[i];
		}

		for (int i = 1; i <= M; i++) {
			int value, idx;
			cin >> value >> idx;

			slot[idx] = value;
		}

		int cnt = 1;
		for (int i = 2; i <= M; i++) {
			if (slot[i] > slot[i - 1]) {
				cnt++;
			}
			else {
				ans += score[cnt];
				cnt = 1;
			}
		}
		ans += score[cnt];

		cout << ans << "\n";
	}

	return 0;
}