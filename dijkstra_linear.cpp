#include <iostream>

using namespace std;

int number = 6;
//int INF = 10000000;
//�׳� 100���� 

int a[6][6] = {
	//{0,2,5,1,INF,INF},
	{0, 2, 5, 1, 100, 100},
	{2, 0, 3, 2, 100, 100},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, 100},
	{100, 100, 1, 1, 0 ,2},
	{100, 100, 5, 100, 2, 0},
};

bool v[6]; // �湮�� ���
int d[6]; // �Ÿ�

//���� �ּ� �Ÿ��� ������ ������ ��ȯ
int getSmallIndex() {
	int min = 100; // INF 
	int index = 0;
	for (int i = 0; i < number; i++) {
		//min������ �۰� �湮���� �ʾ�����
		if (d[i] < min && !v[i]) { 
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
	    //������ ���� ��� ����� �Ÿ��� ��Ƶ�
		d[i] = a[start][i];
	}
	v[start] = true;
	//�ݺ��� ���� �������� ǥ���߰�, ������ ���� �湮�����ʾƵ� �ִܰŸ��� ���� ��
	//���� number(������ ����)-2 
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
}