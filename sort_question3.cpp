#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int n = a.length(), sum = 0;
	for (int i = 0; i < n; i++) {
		//숫자인 경우만 더함
		if (a[i] - '0' <= 0 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	//길이가 짧은 단어가 먼저
	if (a.length() !=b.length()) {
		return a.length() < b.length();
	}
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// 글자에 포함된 숫자의 합으로 정렬
		if (aSum != bSum) {
			//합이 작은 순
			return aSum < bSum;
		}
		else {
			//사전 순 
			return a < b;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		//동일한 단어는 패스하고 출력
		if (i > 0 && a[i] == a[i - 1]) continue;
		cout << a[i] << '\n';
	}
	return 0;
}