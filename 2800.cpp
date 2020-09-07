#include <bits/stdc++.h>

using namespace std;

int main() {
	vector <char> v;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int op, result = 0;
	string exp;
	cin >> exp;

	for (int i = 0; i < exp.size(); i++) {
		v.push_back(exp[i]);
	}

	stack<int> s;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '(' && exp[i + 1] == ')') {
			s.push(2);
			i++;
		}
		else if (exp[i] == '[' && exp[i + 1] == ']') {
			s.push(3);
			i++;
		}
		else if (exp[i] == ')') {
			op = 0;
			while (!s.empty() && s.top() != -1) {
				op += s.top();
				s.pop();
			}
			if (s.empty()) {
				result = 0;
				break;
			}
			s.pop();
			s.push(op * 2);
		}

		else if (exp[i] == ']') {
			op = 0;

			while (!s.empty() && s.top() != -2) {
				op += s.top();
				s.pop();
			}

			if (s.empty()) {
				result = 0;
				break;
			}

			s.pop();
			s.push(op * 3);
		}
		else if (exp[i] == '(') {
			s.push(-1);
		}
		else {
			s.push(-2);
		}

	}

	while (!s.empty()) {
		if (s.top() < 0) {
			result = 0;
			break;
		}
		result += s.top();
		s.pop();
	}

	cout << result << '\n';

	return 0;

}