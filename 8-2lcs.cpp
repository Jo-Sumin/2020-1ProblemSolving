#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;

long long lcs[1001][1001];
char a[1002], b[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(lcs, 0, sizeof(lcs));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		long long ans = 0;
		cin >> (a + 1) >> (b + 1);

		for (int i = 1; a[i] != 0; i++) {
			for (int j = 1; b[j] != 0; j++) {
				if (a[i] == b[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else {
					lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				}
				ans = max(ans, lcs[i][j]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}