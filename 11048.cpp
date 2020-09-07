#include <bits/stdc++.h>

using namespace std;

int dp[1111][1111];
int board[1111][1111];

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			dp[i][j] = board[i][j];
		}
	}


	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--) {
			dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + board[i][j];
		}
	}

	cout << dp[1][1] << '\n';

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}