//didn't understand
//팰린드롬 분할
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s;
int pld[2501][2501];
int d[2501];

int main() {
	cin >> s;
	s.insert(0, " ");
	int size = s.length();
	//1 ex) A
	for (int i = 1; i <= size; i++)
		pld[i][i] = 1;
	//2 ex) BB
	for (int i = 1; i < size; i++) {
		if (s[i] == s[i + 1]) {
			pld[i][i + 1] = 1;
		}
	}
	//3이상 ex) ABA
	for (int i = 2; i < size; i++) {
		for (int j = 1; j <= size - i; j++) {
			if (s[j] == s[i + j] && pld[j + 1][j + i - 1]) {
				pld[j][j + i] = 1;
			}
		}
	}
	
	for (int i = 1; i < size; i++) {
		d[i] = 2147483647; // 임의의 큰수

		for (int j = 1; j <= i; j++) {
			if (pld[j][i]) {
				d[i] = min(d[i], d[j - 1] + 1);
			}
		}
	}
	cout << d[size - 1] << endl;
	return 0;
}