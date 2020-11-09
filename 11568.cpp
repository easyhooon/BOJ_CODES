#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int arr[MAX+1]; //�ε��� i�� �� ��
int dp[MAX+1]; //i��° �� ���� �����ϴ� ���� �ִ� ����(1�� �ʱ�ȭ�ؼ� �ڱ� �ڽŵ� �����ϰ� ����)

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
		//LIS �˰���
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}
	
	cout << max << '\n';
}