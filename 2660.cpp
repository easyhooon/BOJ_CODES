#include <bits/stdc++.h>
using namespace std;

#define MAX 111

int N;
int MIN = 987654321;
int graph[MAX][MAX];
vector<int> answer;

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

	while(true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;

		graph[a][b] = graph[b][a] = 1;
		
	}

	floydWarshall();

	//�ε��� �򰥸��� �ʱ� ����
	vector<int> max_point_v(MAX);

	//ȸ�� �ĺ��� ���� ���ϱ�(�� �ĺ��� ������ �ִ� ���� �� ���� ���� ����)
	for (int i = 1; i <= N; i++) {
		//�ĺ��� ���� ����
		int max_point = 0;
		for (int j = 1; j <= N; j++) {
			//�� �ĺ��� ������ �ִ� ���� ū ���� ã��(�� ������ �� �ĺ��� ����)
			max_point = max(max_point, graph[i][j]);
		}
		//�� �ĺ��� ������ ����
		max_point_v[i] = max_point;
		//�ĺ����� ���� �߿� ���� ���� ���� ã��(ȸ�� �ĺ��� ����)
		MIN = min(MIN, max_point);
	}

	//ȸ�� �ĺ� ã��(������ ���� ȸ�� �ĺ��� ������ ������ ���� ���)
	for (int i = 1; i <= N; i++) {
		if (MIN == max_point_v[i])
			answer.push_back(i);
	}

	sort(answer.begin(), answer.end());

	cout << MIN <<" " <<int(answer.size()) << '\n';

	for (int i = 0; i < int(answer.size()); i++)
		cout << answer[i] << " ";

	return 0;
}