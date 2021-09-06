#include <iostream>
#include <cstring>

using namespace std;

int T, n, d;
int expend[200001];
int cnt[201];

double midCal() {
	double mid = 0;
	int midcnt = 0;

	if (d % 2 != 0) {
		for (int i = 0; i <= 200; i++) {
			midcnt += cnt[i];

			if (midcnt > d / 2) {
				mid = i;
				break;
			}
		}
	}

	else {
		double f1 = 0, f2 = 0;

		for (int i = 0; i <= 200; i++) {
			midcnt += cnt[i];

			if (midcnt >= d / 2 && f1 == 0) {
				f1 = i;
			}
			if (midcnt >= d / 2 + 1 && f2 == 0) {
				f2 = i;
				mid = ((double)(f1 + f2) / 2);
				break;
			}
		}
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(expend, 0, sizeof(expend));
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;

		cin >> n >> d;

		for (int i = 0; i < n; i++)
			cin >> expend[i];

		for (int i = 0; i < d; i++)
			cnt[expend[i]]++;

		for (int i = d; i < n; i++) {
			double mid = midCal();

			if (mid * 2 <= expend[i]) ans++;

			cnt[expend[i - d]]--;
			cnt[expend[i]] ++;
		}
		cout << ans << "\n";
	}

	return 0;
}