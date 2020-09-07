#include <bits/stdc++.h>

using namespace std;
int d[100001];
//d[i]= i를 제곱수의 합으로 나타냈을 때, 필요한 항의 최소 개수
//마지막수가 중요 - (마지막수)^2 + 1
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}

	cout << d[n] << '\n';

	return 0;
}