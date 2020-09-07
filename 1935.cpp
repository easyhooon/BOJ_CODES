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
	for (char ch : postfix) { //문자열의 처음부터 끝 원소 출력 
		if (ch >= 'A' && ch <= 'Z') {
			s.push((double)num[ch - 'A']);
		}
		else {
			//가장 최근에 넣은 두 넘버를 빼서 
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
	cout << fixed << setprecision(2) << s.top() << '\n'; //소수 둘째 자리까지 출력, 있었구나 c언어야 미안해
	return 0;

}