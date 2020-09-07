#include<iostream>
#include<algorithm>

//Knapsack algorithm
using namespace std;

int L[21], J[21];
int K[21][101]; 

int knapsack(int n, int W, int price[], int weight[]) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (weight[i] > j) {
				K[i][j] = K[i - 1][j];
			}
			else {
				K[i][j] = max(K[i - 1][j - weight[i]] + price[i], K[i - 1][j]);
				//i�� �������� ����
				//j�� ������ ũ�� weight[i]�� ������ ���� 
				//j-weight[i] �� ���� ����ũ�⸸ŭ �� �ǹ� 
				//MAX(���� ������ ��ġ+��������ũ�⸸ŭ ������ ������ ���� �� �ִ� ��ġ, �������� ���ص� ������ ��ġ)
			}
		}
	}
	return K[n][W];
}

int main() {

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> J[i];
	}

	cout << knapsack(N, 99, J, L);
	
	printf("\n");


	for (int i = 0; i < 21; i++)    
	{
		for (int j = 0; j < 101; j++)    
		{
			printf("%d ", K[i][j]); 
		}
		printf("\n");                
	}

	return 0;
}
