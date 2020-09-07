#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> d(n);
	//d[i] = a[1],...,a[i]���� ������ ���� ��, a[i]�� ���������� �ϴ� ���� �� �����ϴ� �κ� ������ ����

	//LIS ���� ��� 
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	//���Ϳ��� ���� ū ���Ҹ� ã�� �޼ҵ� 
	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}