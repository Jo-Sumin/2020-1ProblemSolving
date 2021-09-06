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
		cin >> s;

		int idx = 0;
		char tmp[100001];

		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')
				tmp[idx++] = s[i];
			else if (s[i] >= 'A' && s[i] <= 'Z')
				tmp[idx++] = s[i] - 'A' + 'a';
		}

		bool palin = true;

		for (int i = 0; i < idx / 2; i++) {
			if (tmp[i] != tmp[idx - i - 1]) {
				palin = false;
				break;
			}
		}
		if (palin) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}