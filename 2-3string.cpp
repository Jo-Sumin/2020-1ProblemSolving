#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
string s, r;

int fun(string s, string r) {
	int win_cnt[56] = { 0 };
	int r_cnt[56] = { 0 };

	int start = 0, end = 0, win_len = 0, cnt = 0;
	int s_len = s.length(), r_len = r.length();

	int minlen = s_len + 1;

	for (int i = 0; i < r_len; i++) {
		if (r[i] >= 'A' && r[i] <= 'Z')
			r_cnt[r[i] - 'A']++;
		else
			r_cnt[26 + r[i] - 'a']++;
	}

	while (end <= s_len) {
		int start_al, end_al;
		if (s[start] >= 'A' && s[start] <= 'Z') start_al = s[start] - 'A';
		else start_al = 26 + s[start] - 'a';
		if (s[end] >= 'A' && s[end] <= 'Z') end_al = s[end] - 'A';
		else end_al = 26 + s[end] - 'a';

		win_cnt[end_al] ++;
		if (r_cnt[end_al] >= win_cnt[end_al]) cnt++;

		while (cnt == r_len) {
			win_len = end - start + 1;
			minlen = min(win_len, minlen);
			if (r_cnt[start_al] >= win_cnt[start_al]) cnt--;

			win_cnt[start_al]--;
			start++;

			if (s[start] >= 'A' && s[start] <= 'Z') start_al = s[start] - 'A';
			else start_al = 26 + s[start] - 'a';
		}
		end++;
	}
	if (minlen > s_len) return 0;
	return minlen;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {

		cin >> s >> r;

		cout << fun(s, r) << "\n";
	}

	return 0;
}