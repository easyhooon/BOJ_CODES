#include <bits/stdc++.h>

using namespace std;

struct coord
{
	int y, x;
};
int W, H;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int hx[8] = { 2, 1, 2 , 1, -2, -1, -2, -1 };
int hy[8] = { 1, 2, -1, -2, 1, 2, -1, -2 };

int board[222][222];
bool visit[222][222];
int dist[222][222];


bool isin(int y, int x)
{
	return 1 <= y && y <= H && 1 <= x && x <= W;
	//이 조건을 만족하면 1
}

void bfs(int y, int x)
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
			if (isin(ny, nx) && board[ny][nx] == 0 && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				dist[ny][nx] = dist[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int solve()
{
	int max_val = 0;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (board[i][j] != 1 || visit[i][j]) {
				continue;
			}
		}
	}
	return max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;

	cin >> k;

	cin >> W >> H;

	int x, y, ans;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> board[i][j];
		}
	}

	ans = solve();

	cout << ans << '\n';

	return 0;

}

/*#include <bits/stdc++.h>

using namespace std;

int k;
int w, h;
int board[201][201];
bool visited[201][201][31] = { false };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int kdx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int kdy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

struct pos {
	int x;
	int y;
	int k;
	int cnt;
	pos(int a, int b, int c, int d) : x(a), y(b), k(c), cnt(d) {}
};

int bfs(int k) {
	queue<pos> q;
	q.push(pos(0, 0, k, 0));

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.x < 0 || cur.y < 0 || cur.x >= w || cur.y >= h) continue;
		if (board[cur.y][cur.x]) continue;

		if (cur.x == w - 1 && cur.y == h - 1) {
			return cur.cnt;
		}

		if (visited[cur.y][cur.x][cur.k]) continue;
		visited[cur.y][cur.x][cur.k] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			q.push(pos(nx, ny, cur.k, cur.cnt + 1));
		}

		if (cur.k == 0) continue;
		for (int i = 0; i < 8; i++) {
			int nx = cur.x + kdx[i];
			int ny = cur.y + kdy[i];
			q.push(pos(nx, ny, cur.k - 1, cur.cnt + 1));
		}
	}

	return -1;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	cout << bfs(k) << '\n';

	return 0;
}*/