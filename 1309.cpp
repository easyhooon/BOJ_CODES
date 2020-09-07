/*#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[200001][1000001];
//우리의 크기가 i 일때 j마리의 사자가 들어갈 수 있는 경우의 수 
int main() {

	cin >> n;

	dp[2][1] = 2;
	dp[4][1] = 4;
	dp[4][2] = 2;
	//dp[2n][1] = 2n;
	//dp[2n][n] = 2;

	//초기 값

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
			//dp[j] = dp[j](기존의 동전 종류를 이용해 k를 만드는 경우의 수
			//        + dp[j - coins[i]](새 동전 종류 사용하는 경우 추가)
		}
	}

	cout << dp[k];

	return 0;
}*/


//사자를 한 마리도 배치하지 않는 경우도 하나의 경우의 수로 친다고 가정한다. -> 문제 조건 똑바로 보자!
#include <bits/stdc++.h>
using namespace std;

#define MOD 9901

int dp[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
	}

	cout << dp[n] << '\n';

	return 0;
}