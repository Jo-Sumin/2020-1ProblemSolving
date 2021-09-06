#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, L, k;
int bead[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		memset(bead, 0, sizeof(bead));

		cin >> n >> L >> k;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			if (num > 0) bead[i] = L - num;
			
			else bead[i] = -num;
		}

		sort(bead, bead + n);

		cout << bead[k - 1] << "\n";
	}

	return 0;
}