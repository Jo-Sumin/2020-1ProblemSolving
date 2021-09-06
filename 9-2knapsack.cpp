#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, K;
int w[501], v[501];
long long dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(w, 0, sizeof(w));
		memset(v, 0, sizeof(v));
		memset(dp, 0, sizeof(dp));

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> w[i];
		for (int i = 1; i <= N; i++)
			cin >> v[i];

		for (int i = 1; i <= N; i++) {
			for (int j = K; j >= 1; j--) {
				if (w[i] <= j)
					dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		cout << dp[K] << "\n";
	}

	return 0;
}