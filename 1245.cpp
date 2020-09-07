#include <bits/stdc++.h>
using namespace std;
struct coord
{
	int y, x;
};
int n, m, k, peak;
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int board[111][111];
bool visit[111][111];

void init()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 70; j++)
		{
			board[i][j] = 0;
			visit[i][j] = false;
		}
	}
}
bool isin(int y, int x)
{
	return 0 <= y && y <= n && 0 <= x && x <= m;
	//이 조건을 만족하면 1
}
void bfs(int y, int x)
{
	queue<coord> q;

	visit[y][x] = true;
	q.push({y, x});
	while (!q.empty())
	{
		auto top = q.front();
		auto &cy = top.y, &cx = top.x;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (isin(ny, nx) && board[ny][nx] <= board[cy][cx] && !visit[ny][nx])
			{
				//더 큰 곳은 탐색을 하지 못하게 해 산에 봉우리를 한개씩만 세도록 장치를 해둠
				visit[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
}
int solve()
{
	int ans = 0;
	for (peak; peak >= 1; peak--)
	{
		for (int i = 1; i <= n; i++)
		{
			{
				for (int j = 1; j <= m; j++)
				{
					if (board[i][j] != peak || visit[i][j])
						continue;
					//하나의 산의 봉우리가 여러개 있을 수 있다. 라는 조건
					//언제즘 자력으로 문제를 해결할 수 있을까.....
					//peak면 위의 조건문을 통과
					bfs(i, j);
					ans++;
				}
			}
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			peak = max(peak, board[i][j]);
			//전역변수도 0으로 초기화되는듯, 전역배열마냥
		}
	}

	cout << solve() << '\n';
}