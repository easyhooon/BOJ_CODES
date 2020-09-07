#include <bits/stdc++.h>

using namespace std;
int n, cnt;
int tetra[123];

int calculate(int n){
	int k = 1;
	int j = 1;
	int i = 2;
	int index;
	while (true) {
		if (k == 1) tetra[1] = k;
		k = k + ((j + 1) * (j + 2)) / 2;
		if (k > n) {
			index = i - 1;
			break;
		}
		tetra[i] = k;
		j++;
		i++;
	}

	return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int index;
	int cnt = 0;
	cin >> n;

	index = calculate(n);
	cout << index << '\n';
	while (index > 0) {
		cnt += n / tetra[index];
		n = n % tetra[index];
		index--;
	}

	cout << cnt << '\n';

	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int tetra[123];
int dp[300001]; //�Է¹��� ���� �ּ� ���ü �� 

int main() {
	int i, n, index;

	cin >> n;

	for (i = 1; tetra[i - 1] < n; i++) 
		tetra[i] = tetra[i - 1] + i * (i + 1) / 2;

	index = i - 1; //tetra�迭�� ũ�� 

	fill(dp + 1, dp + n + 1, 987654321); //������ ū ������ dp �迭�� ä��

	for (int k = 0; k <= index; k++) dp[tetra[k]] = 1; //dp�迭���� �ش� tetra�迭 ���� �ش��ϴ� �ε����� 1�� ä��-> 1���� ä�� �� �����ϱ�
	
	for (int i = 0; i <= index; i++) {
		for (int j = tetra[i]; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - tetra[i]] + 1); //�Ϻ��� ����x 
			//���ü�� �ʿ��� ���� ��ŭ ���ְ� 1 �����ذŶ�  ������ �ε����� ����ִ� ���� �� 
		}
	}

	cout << dp[n];

	return 0;
}*/