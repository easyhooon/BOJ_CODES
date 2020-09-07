#include <iostream>
#include <stack>
#include <string>

using namespace std;


int solution(string str) {
	int answer = 0;
	stack<char> pipe;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') pipe.push(str[i]);
		else {
			pipe.pop();
			if (str[i - 1] == '(') answer += pipe.size();
			else answer += 1;
		}
	}
	return answer;
}

int main(void) {
	string str;
	cin >> str;
	int answer = solution(str);
	cout << answer;
	return 0;
}

/*int main(void) {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}*/