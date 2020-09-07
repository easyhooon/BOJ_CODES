/*
    3 7 8 1 5 9 6 10 2 4  pivot 3
    3 2 8 1 5 9 6 10 7 4
	3 2 1 8 5 9 6 10 7 4  엇갈림(key값(pivot) 보다 작은 원소를 찾다가 i가 j 보다 커짐 
	1 2 3 // 8 5 9 6 10 7 4  3의 위치 확정
	1 2 3 // 8 5 9 6 10 7 4 pivot 1, pivot 8
	1 2 3 // 8 5 9 6 10 7 4
	1 2 3 // 8 5 9 6 10 7 4
	1 2 3 // 8 5 4 6 10 7 9 //1 2 3 완료 (자기자신을 바꾸는 과정을 진행하였음)
	1 2 3 // 7 5 4 6 //8 10 9
	...
	1 2 3 4 5 6 7 8 9 10
*/
#include <stdio.h>

void quickSort(int* data, int start, int end) {
	if (start >= end) { //원소가 1개인 경우 그대로 두기
		return;
	}

	int key = start; //pivot
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) { ////엇갈릴 때까지 반복
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (j > start && data[j] >= data[key]) {
			j--;
		}
		// >= , <= 반대로 하면 내림차순 
		if (i > j) { //엇갈린 상태
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}


int main(void) {
	int i;
	int data[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	int number = sizeof(data)/sizeof(int);

	quickSort(data, 0, number - 1);
	for (i = 0; i < number; i++) {
		printf("%d ", data[i]); //배열의 이름은 배열의 주소,
		//개념: 배열의 주소가 들어있는 포인터는 인덱스로 접근할 수 있음
		// 1차원 배열이면 * 한개 
		// 배열을 포인터에 할당한 뒤 포인터를 역참조해보면 배열의 첫 번째 요소의 값이 나옵니다. 
		// 마찬가지로 배열 자체도 역참조해보면 배열의 첫 번째 요소의 값이 나옵니다. 
		// 즉, 실제로는 배열도 포인터라 할 수 있습니다.
	    // ex)
		// int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
		// int * numPtr = numArr;
		// printf("%d\n", numPtr[5];
		// 66
		// printf("%d\n", *numPtr);
		// 11
		// printf("%d\n", *numArr);
		// 11
		// 차이점은 크기 ㅇㅇ 
	}
	return 0;
}
