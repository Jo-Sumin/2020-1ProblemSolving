#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
pair<int, int> hanoi[10001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(hanoi, 0, sizeof(hanoi));
		int ans = 1;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			hanoi[i] = { num, i };
		}

		sort(hanoi, hanoi + n, cmp);

		int idx = hanoi[0].second;

		for (int i = 1; i < n; i++) {
			if (idx < hanoi[i].second) {
				idx = hanoi[i].second;
			}
			else {
				idx = hanoi[i].second;
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}