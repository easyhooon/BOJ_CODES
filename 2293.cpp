#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[111];
int dp[10001];
//k �϶� ������ ����� �� 
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> coins[i];

	dp[0] = 1;
	//�ʱ� ��

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
			//if���� �ʿ䰡 ����
			//dp[j] = dp[j](������ ���� ������ �̿��� k�� ����� ����� ��
			//        + dp[j - coins[i]](�� ���� ���� ����ϴ� ��� �߰�)
			//�װ��� �̹� ���(�� ��ŭ ����, ���������� ������ �߿��� ���ε�)
		}
	}

	cout << dp[k];

	return 0;
}