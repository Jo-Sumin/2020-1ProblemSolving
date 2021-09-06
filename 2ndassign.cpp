#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct card {
	int x; int y;
};

typedef struct Dist {

	int x1, y1;

	int x2, y2;
	int dist;
};

int T, N, M;

vector<card> cardVec[26];
vector<Dist> distVec[26];


void clear_card() {
	for (int i = 0; i < 26; i++) {
		cardVec[i].clear();
		distVec[i].clear();
	}
}


bool cmp(Dist a, Dist b) {
	return (a.dist < b.dist) ||
		(a.dist == b.dist && a.y1 + a.y2 < b.y1 + b.y2) ||
		(a.dist == b.dist && a.y1 + a.y2 == b.y1 + b.y2 && a.x1 + a.x2 < b.x1 + b.x2);

}

void fun(vector<card>& v, int shape) {

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			Dist tmp;
			if ((v[j].y < v[i].y) || (v[j].y == v[i].y && v[j].x < v[i].x)) {
				tmp.x1 = v[j].x;
				tmp.y1 = v[j].y;

				tmp.x2 = v[i].x;
				tmp.y2 = v[i].y;
			}
			else {
				tmp.x1 = v[i].x;
				tmp.y1 = v[i].y;

				tmp.x2 = v[j].x;
				tmp.y2 = v[j].y;
			}
			tmp.dist = pow(tmp.x1 - tmp.x2, 2) + pow(tmp.y1 - tmp.y2, 2);
			distVec[shape].push_back(tmp);
		}
	}

	sort(distVec[shape].begin(), distVec[shape].end(), cmp);

	int d_len = distVec[shape].size();
	for (int i = 0; i < d_len; i++) {
		if (distVec[shape][i].dist != -1) {
			cout << (char)('A'+shape) << " "
				<< distVec[shape][i].x1 << " " << distVec[shape][i].y1 << " "
				<< distVec[shape][i].x2 << " " << distVec[shape][i].y2 << "\n";

			for (int j = i + 1; j < d_len; j++) {
				if ((distVec[shape][i].x1 == distVec[shape][j].x1 && distVec[shape][i].y1 == distVec[shape][j].y1) ||
					(distVec[shape][i].x1 == distVec[shape][j].x2 && distVec[shape][i].y1 == distVec[shape][j].y2) ||
					(distVec[shape][i].x2 == distVec[shape][j].x1 && distVec[shape][i].y2 == distVec[shape][j].y1) ||
					(distVec[shape][i].x2 == distVec[shape][j].x2 && distVec[shape][i].y2 == distVec[shape][j].y2))
					distVec[shape][j].dist = -1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		clear_card();

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			char al;
			int x, y;
			cin >> al >> x >> y;
			
			cardVec[al - 'A'].push_back({ x, y });
		}

		for (int i = 0; i < 26; i++) {
			if (!cardVec[i].empty()) {
				fun(cardVec[i], i);
			}
		}

		
	}
	return 0;
}