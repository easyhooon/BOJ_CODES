#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define MAX 101

int N, M;
int graph[MAX][MAX];

//k�� �������

void floydWarshall(void)
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				//1->1 �̷��� ������ 0�̶� 
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j])
					//��ΰ� �����Ѵٸ� true �ƴϸ� false
				{
					if (graph[i][j] == 0)
						//�ѹ��� ������ ������带 ���� Ž���� �����Ҷ�
						graph[i][j] = graph[i][k] + graph[k][j];
					
					else
						//�ٽ�! �� ���� ��η� ���� 
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					
				}
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		//�ѹ��� ���� ��ΰ� �����ϸ� 1 
		graph[node1][node2] = graph[node2][node1] = 1;
	}

	floydWarshall();

	int result = INF;
	int person;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += graph[i][j];

		if (result > sum) 
		{
			//���⼭ ���� ������ i�� ���ŵǸ鼭 result�� �����ϱ⶧���� ������ ���͵� ������ count ��
			//�ε�ȣ�� ����
			result = sum;
			person = i;
		}
	}
	cout << person << '\n';

	return 0;
}