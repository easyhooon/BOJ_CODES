#include <bits/stdc++.h>

using namespace std;
int number[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m,n,max,min;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> number[i];
	}

	cin >> n;

	max = number[0];
	min = number[0];
	
	for (int i = 0; i < m; i++) {
		if (number[i] > max) {
			max = number[i];
		}
		if (number[i] < min) {
			min = number[i];
		}
	}

	long long ans = 0;
	//long long left = min;
	//need understand 
	long long left = 0; //0 이어야 밑에 함수에서 갱신이 됨 
	long long right = max;

	while (left <= right) {
		long long mid = (left + right) / 2;
		int result = 0;

		for (int i = 0; i < m; i++) {
			if (mid > number[i]) result += number[i];
			else result += mid;
		}

		if (result <= n)
		{
			left = mid + 1;
			//need understand
			
		}
		else {
			right = mid - 1;
			if (mid > ans)
				ans = mid;
		}
		

	}

	cout << ans << '\n';


	return 0;
		 
}