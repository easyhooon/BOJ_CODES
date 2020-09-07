#include <bits/stdc++.h>
using namespace std;

#define MAX 111

int N, M, min_cost;
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
	//���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (graph[a][b] != 0) {
			min_cost = min(c, graph[a][b]);
			graph[a][b] = min_cost;
		}
		else {
			graph[a][b] = c;
		}
	}

	floydWarshall();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}