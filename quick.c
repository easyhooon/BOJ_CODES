/*
    3 7 8 1 5 9 6 10 2 4  pivot 3
    3 2 8 1 5 9 6 10 7 4
	3 2 1 8 5 9 6 10 7 4  ������(key��(pivot) ���� ���� ���Ҹ� ã�ٰ� i�� j ���� Ŀ�� 
	1 2 3 // 8 5 9 6 10 7 4  3�� ��ġ Ȯ��
	1 2 3 // 8 5 9 6 10 7 4 pivot 1, pivot 8
	1 2 3 // 8 5 9 6 10 7 4
	1 2 3 // 8 5 9 6 10 7 4
	1 2 3 // 8 5 4 6 10 7 9 //1 2 3 �Ϸ� (�ڱ��ڽ��� �ٲٴ� ������ �����Ͽ���)
	1 2 3 // 7 5 4 6 //8 10 9
	...
	1 2 3 4 5 6 7 8 9 10
*/
#include <stdio.h>

void quickSort(int* data, int start, int end) {
	if (start >= end) { //���Ұ� 1���� ��� �״�� �α�
		return;
	}

	int key = start; //pivot
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) { ////������ ������ �ݺ�
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (j > start && data[j] >= data[key]) {
			j--;
		}
		// >= , <= �ݴ�� �ϸ� �������� 
		if (i > j) { //������ ����
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
		printf("%d ", data[i]); //�迭�� �̸��� �迭�� �ּ�,
		//����: �迭�� �ּҰ� ����ִ� �����ʹ� �ε����� ������ �� ����
		// 1���� �迭�̸� * �Ѱ� 
		// �迭�� �����Ϳ� �Ҵ��� �� �����͸� �������غ��� �迭�� ù ��° ����� ���� ���ɴϴ�. 
		// ���������� �迭 ��ü�� �������غ��� �迭�� ù ��° ����� ���� ���ɴϴ�. 
		// ��, �����δ� �迭�� �����Ͷ� �� �� �ֽ��ϴ�.
	    // ex)
		// int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
		// int * numPtr = numArr;
		// printf("%d\n", numPtr[5];
		// 66
		// printf("%d\n", *numPtr);
		// 11
		// printf("%d\n", *numArr);
		// 11
		// �������� ũ�� ���� 
	}
	return 0;
}
