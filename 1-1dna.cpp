#include <iostream>
#include <cstring>

using namespace std;

int T, N, M;

char dna[51][1001];
int base[4]; //A C G T
char result[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		memset(dna, 0, sizeof(dna));
		memset(result, 0, sizeof(result));
		cin >> M >> N;

		
		int hamming = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dna[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			memset(base, 0, sizeof(base));
			int maxcnt = 0;
			int idx = 0;

			for (int j = 0; j < M; j++) {
				if (dna[j][i] == 'A') {
					base[0]++;
				}
				else if (dna[j][i] == 'C') {
					base[1]++;
				}
				else if (dna[j][i] == 'G') {
					base[2]++;
				}
				else if (dna[j][i] == 'T') {
					base[3]++;
				}
			}

			maxcnt = base[0];
			
			for (int j = 1; j < 4; j++) {
				if (base[j] > maxcnt) {
					maxcnt = base[j];
					idx = j;
				}
			}

			if (idx == 0) {
				result[i] = 'A';
				for (int j = 0; j < M; j++)
					if (dna[j][i] != 'A') hamming++;
			}
			else if (idx == 1) {
				result[i] = 'C';
				for (int j = 0; j < M; j++)
					if (dna[j][i] != 'C') hamming++;
			}
			else if (idx == 2) {
				result[i] = 'G';
				for (int j = 0; j < M; j++)
					if (dna[j][i] != 'G') hamming++;
			}
			else if (idx == 3) {
				result[i] = 'T';
				for (int j = 0; j < M; j++)
					if (dna[j][i] != 'T') hamming++;
			}
		}
		cout << result << "\n" << hamming << "\n";
	}

	return 0;
}