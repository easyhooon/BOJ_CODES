#include <iostream>

using namespace std;

int n, m;
int a[10001];

//�迭�� ���������� �����ϸ� ��� ���Ұ� 0���� �ʱ�ȭ �� 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		}
	}
}