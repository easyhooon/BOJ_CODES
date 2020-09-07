//문제 이해 제대로 

/*#include <bits/stdc++.h>
using namespace std;

int arr[1011];
int dp[1011]; //i번째에 i번째 미만의 상자를 넣을 수 있는 최대 상자 개수 

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				cnt++;
		}
		dp[i] = max(dp[i - 1], cnt);
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << '\n';

	//cout << dp[n] << '\n';
}*/

//LIS에 대한 이해

#include <bits/stdc++.h>

using namespace std;

int arr[1011]; //인덱스 i일 때 값
int dp[1011]; //i번째 수 까지 증가하는 수의 최대 개수(1로 초기화해서 자기 자신도 포함하게 만듬)

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
		//이 식 자체가 LIS 알고리즘 구현 한거임
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}

	/*for (i = 1; i <= n; i++) {
		cout << dp[i];
	}*/


	cout << max << '\n';
}

