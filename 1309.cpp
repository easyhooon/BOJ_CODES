/*#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[200001][1000001];
//�츮�� ũ�Ⱑ i �϶� j������ ���ڰ� �� �� �ִ� ����� �� 
int main() {

	cin >> n;

	dp[2][1] = 2;
	dp[4][1] = 4;
	dp[4][2] = 2;
	//dp[2n][1] = 2n;
	//dp[2n][n] = 2;

	//�ʱ� ��

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
			//dp[j] = dp[j](������ ���� ������ �̿��� k�� ����� ����� ��
			//        + dp[j - coins[i]](�� ���� ���� ����ϴ� ��� �߰�)
		}
	}

	cout << dp[k];

	return 0;
}*/


//���ڸ� �� ������ ��ġ���� �ʴ� ��쵵 �ϳ��� ����� ���� ģ�ٰ� �����Ѵ�. -> ���� ���� �ȹٷ� ����!
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