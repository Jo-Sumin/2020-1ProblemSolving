#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int student[10001];
int result;
bool visited[10001];
bool done[10001];

void dfs(int n) {
	visited[n] = true;

	int next = student[n];
	if (!visited[next])
		dfs(next);

	else {
		if (!done[next]) {
			for (int i = next; i != n; i = student[i])
				result++;
			result++;
		}
	}
	done[n] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		memset(student, 0, sizeof(student));
		memset(done, 0, sizeof(done));
		memset(visited, 0, sizeof(visited));

		result = 0;
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> student[i];

		for (int i = 1; i <= N; i++)
			if (!visited[i]) dfs(i);

		cout << N - result << "\n";
	}

	return 0;
}