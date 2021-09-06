#include <iostream>
#include <cstring>
using namespace std;

int T;
int M, N;
char codeword[26][129];
string encode;
int bitlen;
int hamming[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(codeword, 0, sizeof(codeword));
		string ans;
		bitlen = 0;

		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)
				cin >> codeword[i][j];
		}

		cin >> bitlen >> encode;

		for (int i = 0; i < (bitlen / N); i++) {
			memset(hamming, 0, sizeof(hamming));
		
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < N; k++) {
					if (codeword[j][k] != encode[k + i * N])
						hamming[j] ++;
				}
			}
			int minimum = hamming[0];
			int minidx = 0;

			for (int j = 1; j < M; j++) {
				if (minimum > hamming[j]) {
					minidx = j;
					minimum = hamming[j];
				}
			}
			ans = ans + char(minidx + 'A');
		}
		cout << ans << "\n";
	}

	return 0;
}