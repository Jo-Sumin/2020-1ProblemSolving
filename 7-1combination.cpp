#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1013

using namespace std;

int T, N, a, b, x;
int num[10];
int cnt;

void comb(int s, int e) {
	if (s == e) {
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += num[i] * pow(x, i);
		}
		sum %= MOD;

		if (sum >= a && sum <= b) cnt++;
	}

	else {
		for (int i = s; i <= e; i++) {
			swap(num[s], num[i]);
			comb(s + 1, e);
			swap(num[s], num[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(num, 0, sizeof(num));
		cnt = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> num[i];

		cin >> a >> b >> x;
		comb(0, N - 1);
		cout << cnt << "\n";
	}

	return 0;
}