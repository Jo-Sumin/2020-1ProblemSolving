#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, K;
pair<int, int> p[501]; // 무게 가치

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.second / a.first) > (b.second / b.first);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(p, 0, sizeof(p));
		int ans = 0;

		cin >> N >> K;
		
		for (int i = 0; i < N; i++)
			cin >> p[i].first;
		for (int i = 0; i < N; i++)
			cin >> p[i].second;

		sort(p, p + N, cmp);

		int idx = 0;
		while (idx < N && K >= p[idx].first) {
			K -= p[idx].first;
			ans += p[idx].second;
			idx++;
		}
		ans += (p[idx].second / p[idx].first) * K;
		cout << ans << "\n";
	}

	return 0;
}