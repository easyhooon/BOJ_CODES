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
	//�� ������ �����ϸ� 1
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
				//�� ū ���� Ž���� ���� ���ϰ� �� �꿡 ���츮�� �Ѱ����� ������ ��ġ�� �ص�
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
					//�ϳ��� ���� ���츮�� ������ ���� �� �ִ�. ��� ����
					//������ �ڷ����� ������ �ذ��� �� ������.....
					//peak�� ���� ���ǹ��� ���
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
			//���������� 0���� �ʱ�ȭ�Ǵµ�, �����迭����
		}
	}

	cout << solve() << '\n';
}