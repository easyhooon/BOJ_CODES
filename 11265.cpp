#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, a, b, c;
int graph[501][501];

void floydWarshall(void)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j])
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}
	}

	floydWarshall();

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 	{
	// 		cout << graph[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;

		if (graph[a][b] > c)
			cout << "Stay here" << '\n';

		else
			cout << "Enjoy other party" << '\n';
	}

	return 0;
}