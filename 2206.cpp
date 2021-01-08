#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int n, m;
int board[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1][2];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct pos
{
    int x;
    int y;
    int k;
    int cnt;
    pos(int a, int b, int c, int d) : x(a), y(b), k(c), cnt(d) {}
};

int bfs()
{
    queue<pos> q;

    visited[0][0][1] = true;
    q.push(pos(0, 0, 1, 1));

    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        // cout << cur.x << cur.y << cur.k << '\n';

        if (cur.x == m - 1 && cur.y == n - 1)
        {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n)
            {
                if (board[ny][nx] == 0 && visited[ny][nx][cur.k] == false)
                {
                    visited[ny][nx][cur.k] = true;
                    q.push(pos(nx, ny, cur.k, cur.cnt + 1));
                }
                else if (board[ny][nx] == 1 && cur.k == 1)
                {
                    visited[ny][nx][cur.k -1] = true;
                    q.push(pos(nx, ny, cur.k -1, cur.cnt + 1));
                }
            }
        }
    }

    return -1;
}

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 0; j < m; j++)
        {
            int tmp = inp[j] - '0';
            board[i][j] = tmp;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j];
    //     }
    //     cout <<'\n';
    // }

    cout << bfs() << '\n';

    return 0;
}