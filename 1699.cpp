#include <bits/stdc++.h>

using namespace std;
int d[100001];
//d[i]= i�� �������� ������ ��Ÿ���� ��, �ʿ��� ���� �ּ� ����
//���������� �߿� - (��������)^2 + 1
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}

	cout << d[n] << '\n';

	return 0;
}