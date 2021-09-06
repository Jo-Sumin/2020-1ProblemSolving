#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int parent[1001];
pair<int, int> a[1001];
vector<pair< pair<int, int> , int> > v;

bool cmp(pair< pair<int, int>, int> a, pair< pair<int, int>, int> b) {
	return a.second < b.second;
}

int findparent(int x) {
	if (parent[x] == x)return x;
	return parent[x] = findparent(parent[x]);
}

bool find(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a != b) return true;
	else return false;
}

void setparent(int a, int b) {
	a = findparent(a);
	b = findparent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;

	while (T--) {
		memset(parent, 0, sizeof(parent));
		memset(a, 0, sizeof(a));
		v.clear();

		cin >> N;

		int ans = 0; parent[0] = 0;

		for (int i = 1; i <= N; i++) {
			int x, y;
			cin >> x >> y;
			a[i] = { x, y };
			parent[i] = i;

			v.push_back({ {0, i}, x });
			ans += x;
		}

		for (int i = 1; i < N; i++) {
			v.push_back({ {i, i + 1}, a[i + 1].second });
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++) {
			if (find(v[i].first.first, v[i].first.second)) {
				setparent(v[i].first.first, v[i].first.second);
				ans += v[i].second;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}