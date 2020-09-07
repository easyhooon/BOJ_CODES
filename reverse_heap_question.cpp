#include <iostream>
#include <vector>

using namespace std;

int number;
int heap[1000001];

void heapify(int i) {
	//왼쪽 자식 노드를 가리킴
	int c = 2 * i + 1;

	//오른쪽 자식 노드가 있고, 왼쪽 자식노드보다 크다면
	if (c < number-1 && heap[c] < heap[c + 1]) {
		c++;
	}
	//부모보다 자식이 더 크다면 위치 교환
	if (heap[i] < heap[c]) {
		int temp = heap[i];
		heap[i] = heap[c];
		heap[c] = temp;
	}
	//number /2 까지만
	if (c <= number / 2) heapify(c);
}

int main(void) {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> heap[i];
	}
	//힙 생성
	for (int i = number / 2 -1; i >= 0; i--) {
		heapify(i);
	}

	//정렬 수행
	for (int i = number - 1; i >= 0; i--) {
		for (int j = 0; j < number; j++) {
			cout << heap[j] << ' ';
		}
		cout << '\n';
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;

		do {
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1]) c++;
			if (c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
}