/*#include <bits/stdc++.h>

using namespace std;

vector <int> v[1001];
bool check[1001];
int N, M;

void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (check[y] == false)
		{
			dfs(y);
		}
	}
}

int count_components()
{
	int components = 0;

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			components++;
		}
	}

	return components;
}

int main()
{
	int x, y;
	int result = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); //양쪽으로 연결해줘야 함 
	}

	result = count_components();

	cout << result << '\n';

	return 0;
}*/