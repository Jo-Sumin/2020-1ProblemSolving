#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

int T, M, N;

char Left[10];
long long Right;
long long result;

string infix;
string post;
stack<char> op;
stack<long long> cal;

int cmp_op(char c) {
	if (c == '+') return 0;
	else return 1;
}

string in_to_post(string in) {
	string postfix = "";
	int len = in.length();

	for (int i = 0; i < len; i++) {
		if (in[i] >= '0' && in[i] <= '9')
			postfix += in[i];
		else {
			if (op.empty()) op.push(in[i]);
			else if (in[i] == '*' || in[i] == '+') {
				if (in[i] == '*' && op.top() == '+') op.push(in[i]);

				else {
					while (!op.empty() && cmp_op(in[i]) <= cmp_op(op.top())) {
						postfix += op.top();
						op.pop();
					}
					op.push(in[i]);
				}
			}
		}
	}
	while (!op.empty()) {
		postfix += op.top();
		op.pop();
	}
	return postfix;
}

long long Cal(string post) {
	int len = post.length();

	for (int i = 0; i < len; i++) {
		if (post[i] >= '0' && post[i] <= '9')
			cal.push(post[i] - '0');
		else {
			if (post[i] == '+') {
				int tmp = cal.top();
				cal.pop();

				tmp += cal.top();
				cal.pop();
				cal.push(tmp);
			}
			else {
				int tmp = cal.top();
				cal.pop();

				tmp *= cal.top();
				cal.pop();
				cal.push(tmp);
			}
		}
	}
	long long tmp = cal.top();
	cal.pop();
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {

		cin >> M >> N;

		while (M--) {
			memset(Left, 0, sizeof(Left));
			Right = 0;
			infix = "";
			post = "";
			result = 0;

			for (int i = 0; i < N; i++)
				cin >> Left[i];
			cin >> Right;

			for (int i = 0; i < N; i++) {
				infix = infix + Left[i] + " ";
			}

			int flag_find = 0;
			int op_set = pow(2, N - 1) - 1;

			while (op_set >= 0) {
				int mask = 1;

				for (int i = 0; i < N - 1; i++) {
					if (op_set & mask) infix[i * 2 + 1] = '+';
					else infix[i * 2 + 1] = '*';
					mask <<= 1;
				}

				post = in_to_post(infix);
				result = Cal(post);

				if (result == Right) {
					flag_find = 1;
					break;
				}

				op_set--;
			}
			if (flag_find) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}

	return 0;
}