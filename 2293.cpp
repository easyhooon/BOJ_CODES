#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[111];
int dp[10001];
//k 일때 가능한 경우의 수 
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> coins[i];

	dp[0] = 1;
	//초기 값

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
			//if문은 필요가 없다
			//dp[j] = dp[j](기존의 동전 종류를 이용해 k를 만드는 경우의 수
			//        + dp[j - coins[i]](새 동전 종류 사용하는 경우 추가)
			//그것을 이미 사용(그 만큼 삭제, 수학적으로 굉장히 중요한 마인드)
		}
	}

	cout << dp[k];

	return 0;
}