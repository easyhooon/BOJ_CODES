#include <stdio.h>

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main(void) {
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2; // 부모노드 
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0]; // 루트에 있는 원소와 가장 마지막 원소를 교환
		heap[0] = heap[i]; 
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1; // 자식 원소 
			// 자식 중 더 큰 값 찾기
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				// c < i-1 -> 범위 예외처리(이진트리 노드의 왼쪽값이므로)
				c++; //오른쪽 값이 더 큰경우 c의 위치를 오른쪽 값으로 이동 
			}
			//루트보다 자식이 크다면 교환
			if (c < i && heap[root] < heap[c]) {
				// c < i -> 이진트리 노드의 오른쪽 값이 여도 상관없으므로
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	//결과 출력

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}