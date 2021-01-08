#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define MAX 101

int N, M;
int graph[MAX][MAX];

//k는 경유노드

void floydWarshall(void)
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				//1->1 이런거 어차피 0이라 
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j])
					//경로가 존재한다면 true 아니면 false
				{
					if (graph[i][j] == 0)
						//한번엔 못가도 경유노드를 거쳐 탐색이 가능할때
						graph[i][j] = graph[i][k] + graph[k][j];
					
					else
						//핵심! 더 빠른 경로로 갱신 
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

		//한번에 가는 경로가 존재하면 1 
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
			//여기서 작은 수부터 i가 갱신되면서 result를 갱신하기때문에 동률이 나와도 적은게 count 됨
			//부등호라서 ㅇㅇ
			result = sum;
			person = i;
		}
	}
	cout << person << '\n';

	return 0;
}