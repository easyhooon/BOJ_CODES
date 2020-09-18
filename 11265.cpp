#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MAX 501

int n, m;
int graph[MAX][MAX];


void floydWarshall(void)
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j])
				{
					if (graph[i][j] == 0)
						graph[i][j] = graph[i][k] + graph[k][j];
					
					else
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					
				}
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i][j]
 
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
			result = sum;
			person = i;
		}
	}
	cout << person << endl;
	return 0;
}