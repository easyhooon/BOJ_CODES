#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int arr[MAX+1];
int dp[MAX+1];
int v[MAX+1];

void go(int p) {
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p]);
	cout << arr[p] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				v[i] = j;
			}
		}
	}
	int ans = dp[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
			p = i;
		}
	}
	cout << ans << '\n';
	go(p);
	cout << '\n';

	return 0;
}