#include <bits/stdc++.h>

using namespace std;
int top[500001];
int ans[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> top[i];
	}

	for (int j = n; j >= 1; j--) {
		int k = 1;
		while (true) {
			if (top[j] < top[j - k]) {
				ans[j] = j - k;
				break;
			}

			if (j - k < 1) {
				ans[j] = 0;
				break;
			}
			else {
				k++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	/*for (int i = 1; i <= n; i++) {
		s.push(top[i]);
	}*/


	return 0;

}