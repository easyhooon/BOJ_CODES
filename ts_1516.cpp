//inDegree => 진입차수

#include <bits/stdc++.h>
#define MAX 501

using namespace std;

int n, inDegree[MAX], dtime[MAX], result[MAX];

vector<int> v[MAX];

void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			result[i] = dtime[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		int vsize = v[x].size();
		q.pop();

		for (int i = 0; i < vsize; i++)
		{
			int y = v[x][i];
			result[y] = max(result[y], result[x] + dtime[y]);
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> dtime[i];

		while (1)
		{
			int x;
			cin >> x;
			if (x == -1)
				break;
			inDegree[i]++;
			v[x].push_back(i);
		}
	}
	topologySort();
}