#include <bits/stdc++.h>

using namespace std;
int number[100001];

int search(int m, int n) {
	int left = 1;
	int right = INT_MAX;
	int temp, mid;
	int ans = 0;


	while (left <= right) {
		mid = (left + right) / 2;
		temp = mid;
		int count = 0;

		for (int i = 0; i < m; i++) {
			mid = mid - number[i];
			if (mid <= number[i + 1]) {
				mid = temp;
				count++;
				continue;
			}
		}

		if (count < n)
		{
			mid = temp;
			right = mid - 1;

		}
		else {
			mid = temp;
			left = mid + 1;
			if (mid > ans)
				ans = mid;
		}

		if (count >= n)
		{
			mid = temp;
			right = mid - 1;

		}
		else {
			mid = temp;
			left = mid + 1;
			if (mid > ans)
				ans = mid;
		}
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		cin >> number[i];
	}

	cout << search(m, n) << '\n';

	return 0;
	
}