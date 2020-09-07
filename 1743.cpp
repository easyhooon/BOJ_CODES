/*#include <bits/stdc++.h>

using namespace std;

struct coord
{
	int y, x;
};
int n, m, k;
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
int board[111][111];
bool visit[111][111];


bool isin(int y, int x)
{
	return 1 <= y && y <= n && 1 <= x && x <= m;
	//이 조건을 만족하면 1 
}
int bfs(int y, int x)
{
	queue<coord> q;

	visit[y][x] = true;
	q.push({ y, x });

	int cnt = 1;
	while (!q.empty())
	{
		auto top = q.front();
		auto &cy = top.y, &cx = top.x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (isin(ny, nx) && board[ny][nx] == 1 && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}
	return cnt;
}
int solve()
{
	int max_val = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
				/*if (board[i][j] != 1 || visit[i][j]) {
					continue;
				}*/

//진입 조건을 만족했으므로 쓰레기 1개로 일단 취급
//(bfs안에서 초기의 y,x쌍에는 cnt++를 못해주므로)
//cnt = 1;

/*if (board[i][j] == 1 && !visit[i][j])
				{
					max_val = max(max_val, bfs(i, j));
					
				}
				//cnt = 0;
		}
	}
	return max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	int x, y, ans;

	for (int i = 1; i <= k; i++) {
		cin >> y >> x;
		board[y][x] = 1;
	}

	ans = solve();

	cout << ans << '\n';

	return 0;

}*/

#include <bits/stdc++.h>

using namespace std;

struct coord
{
	int y, x;
};
int n, m, k, cnt;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int board[111][111];
bool visit[111][111];


bool isin(int y, int x)
{
	return 1 <= y && y <= n && 1 <= x && x <= m;
	//이 조건을 만족하면 1 
}
int bfs(int y, int x)
{
	queue<coord> q;

	visit[y][x] = true;
	q.push({ y, x });

	while (!q.empty())
	{
		auto top = q.front();
		auto &cy = top.y, &cx = top.x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (isin(ny, nx) && board[ny][nx] == 1 && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				cnt++;
				q.push({ ny, nx });
			}
		}
	}
	return cnt;
}

int solve()
{
	int max_val = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] != 1 || visit[i][j]) {
				continue;
			}

			//진입 조건을 만족했으므로 쓰레기 1개로 일단 취급
			//(bfs안에서 초기의 y,x쌍에는 cnt++를 못해주므로)
			cnt = 1;

			max_val = max(max_val, bfs(i,j));

		}
	}
	return max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	int x, y, ans;

	for (int i = 1; i <= k; i++) {
		cin >> y >> x;
		board[y][x] = 1;
	}

	ans = solve();

	cout << ans << '\n';

	return 0;

}