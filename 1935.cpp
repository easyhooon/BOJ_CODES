#include <bits/stdc++.h>

using namespace std;
int num[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string postfix;
	cin >> n;
	cin >> postfix;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	stack<double> s;
	for (char ch : postfix) { //���ڿ��� ó������ �� ���� ��� 
		if (ch >= 'A' && ch <= 'Z') {
			s.push((double)num[ch - 'A']);
		}
		else {
			//���� �ֱٿ� ���� �� �ѹ��� ���� 
			double op2 = s.top(); s.pop();
			double op1 = s.top(); s.pop();
			if (ch == '+') {
				s.push(op1 + op2);
			}
			else if (ch == '-') {
				s.push(op1 - op2);
			}
			else if (ch == '*') {
				s.push(op1 * op2);
			}
			else if (ch == '/') {
				s.push(op1 / op2);
			}
		}
	}
	cout << fixed << setprecision(2) << s.top() << '\n'; //�Ҽ� ��° �ڸ����� ���, �־����� c���� �̾���
	return 0;

}