#include <iostream>

using namespace std;

int n, m;
int a[10001];

//배열을 전역변수로 설정하면 모든 원소가 0으로 초기화 됨 

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