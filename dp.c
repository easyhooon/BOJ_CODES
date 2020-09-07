#include <stdio.h>

//전역 변수로 배열 선언시 모든 원소가 0으로 초기화 됨
int d[100];

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];
	// 이미 값을 만들어 놓았다면, return - memoization
	return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main(void) {
	printf("%d", fibonacci(30));
}

