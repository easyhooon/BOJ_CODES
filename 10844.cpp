#include <bits/stdc++.h>

using namespace std;

long long d[101][10];
//길이가 i이고 마지막 숫자가 j인 계단 수 의 개수
long long mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) {
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	ans %= mod;
	cout << ans << '\n';
	return 0;
}