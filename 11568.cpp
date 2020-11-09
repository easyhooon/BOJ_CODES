#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int arr[MAX+1]; //인덱스 i일 때 값
int dp[MAX+1]; //i번째 수 까지 증가하는 수의 최대 개수(1로 초기화해서 자기 자신도 포함하게 만듬)

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j, n;
	int max = 0;

	cin >> n;

	for (i = 1; i <= n; i++) 
		cin >> arr[i];

	for (i = 1; i <= n; i++) {
		dp[i] = 1;
		for (j = 1; j < i; j++) {
		//LIS 알고리즘
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}
	
	cout << max << '\n';
}