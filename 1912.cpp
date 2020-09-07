#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> d(n);
	//i번째 수로 끝나는 가장 큰 연속합 

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}

	cout << ans << '\n';
	return 0;
}