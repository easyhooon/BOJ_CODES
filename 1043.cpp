#include <bits/stdc++.h>
using namespace std;

int know[55];
int arr[55];

int main()
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, k, cnt;
	int ans = 0;
	cin >> n >> m;

	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> know[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> cnt;
		{
			for (int j = 1; j <= cnt; j++)
			{
				cin >> arr[i];
				int flag = 0;
				for (int l = 1; l <= k; l++)
				{
					for (int m = 1; m <= cnt; m++)
					{
						if (know[l] == arr[m])
							flag++;
					}
				}
				if (flag == 0)
					ans++;
			}
		}
	}

	cout << ans << '\n';
}