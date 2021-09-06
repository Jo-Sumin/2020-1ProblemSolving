#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T, n;
vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		v.clear();
		int ans = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			int start, end;
			cin >> s >> start >> end;

			v.push_back({ start, end });
		}

		sort(v.begin(), v.end(), cmp);

		int now = 0;

		for (int i = 0; i < n; i++) {
			if (v[i].first >= now) {
				now = v[i].second;
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}