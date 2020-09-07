#include <bits/stdc++.h>
using namespace std;

#define MAX 111

int N, M, min_cost;
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
	//시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
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