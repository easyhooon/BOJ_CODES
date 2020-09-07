//���� ���� ����� 

/*#include <bits/stdc++.h>
using namespace std;

int arr[1011];
int dp[1011]; //i��°�� i��° �̸��� ���ڸ� ���� �� �ִ� �ִ� ���� ���� 

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

//LIS�� ���� ����

#include <bits/stdc++.h>

using namespace std;

int arr[1011]; //�ε��� i�� �� ��
int dp[1011]; //i��° �� ���� �����ϴ� ���� �ִ� ����(1�� �ʱ�ȭ�ؼ� �ڱ� �ڽŵ� �����ϰ� ����)

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
		//�� �� ��ü�� LIS �˰��� ���� �Ѱ���
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

