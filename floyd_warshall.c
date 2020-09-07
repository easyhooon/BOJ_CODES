#include <stdio.h>

int number = 4;
//4로 표현
//int INF = 10000000;
//100으로 표현

int a[4][4] = {
	{0, 5, 100, 8},
    {7, 0, 9, 100},
    {2, 100, 0, 4},
    {100, 100, 3, 0}
};

void floydWarshall() {
	int d[4][4];
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드

	for (int k = 0; k < number; k++) {
		//i = 출발 노드
		for (int i = 0; i < number; i++) {
			//j = 도착 노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//결과 출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	floydWarshall();
	
}