#include <bits/stdc++.h>

using namespace std;

long arr1[111111];
long arr2[111111];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr1[i];
	}
	cin >> n;
	for (int j = 1; j <= n; j++) {
		cin >> arr2[j];
	}
	
	sort(arr1+1, arr1 + m+1);

    for (int i = 1; i <= n; i++) {
		if (binary_search(arr1+1, arr1+m+1, arr2[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	
}