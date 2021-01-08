#include <bits/stdc++.h>
using namespace std;

#define MOD 9901

int dp[100001][3]; // 세로가 i칸일때 넣을 수 있는 사자의 마릿 수 
int ans;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

    //기저조건 
	//[0]: 사자가 없는 경우, [1]:사자가 왼쪽에 있는 경우, [2]: 사자가 오른쪽에 있는 경우
	dp[1][0] = 1; 
	dp[1][1] = 1;
	dp[1][2] = 1;                                                          

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}

	 ans = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

     cout << ans << '\n';

	return 0;
}