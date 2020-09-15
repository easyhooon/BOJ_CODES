#include <bits/stdc++.h>
using namespace std;

int a[1011];
int d[3][1011][33];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w, ans;

	cin >> t >> w;

	for (int i = 1; i <= t; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= w + 1; j++)
		{
			if (a[i] == 1)
			{
				d[1][i][j] = max(d[1][i - 1][j] + 1, d[2][i - 1][j - 1] + 1);
				d[2][i][j] = max(d[1][i - 1][j - 1], d[2][i - 1][j]);
			}
			else
			{
				if (i == 1 && j == 1)
					continue;

				d[1][i][j] = max(d[1][i - 1][j], d[2][i - 1][j - 1]);
				d[2][i][j] = max(d[1][i - 1][j - 1] + 1, d[2][i - 1][j] + 1);
			}
		}
	}

	ans = 0;

	for (int i = 1; i <= w + 1; i++)
	{

		if (ans < max(d[1][t][i], d[2][t][i]))
			ans = max(d[1][t][i], d[2][t][i]);
	}

	cout << ans << '\n';

	return 0;
}