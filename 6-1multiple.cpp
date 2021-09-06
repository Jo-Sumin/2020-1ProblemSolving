#include <iostream>
#include <cstring>

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		string s;
		int n;

		cin >> s >> n;

		int len = s.length();
		int num = 0;

		for (int i = 0; i < len; i++) {
			num = num * 10 + (s[i] - '0');
			if (num >= n)
				num %= n;
		}

		if (!num) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}