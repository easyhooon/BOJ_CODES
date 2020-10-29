#include <bits/stdc++.h>

using namespace std;

int n, t, x, y, ny, nx, dist;
bool flag;
int board[65][65];
int check;

vector<pair<int, int>> v;

bool bfs(int y, int x)
{
    while (!q.empty())
    {
        x = q.front().second;
        y = q.front().first;

        q.pop();

        cnt = board[y][x];

        for (int i = 0; i < 2; i++)
        {
            ny = y + cnt * i;
            nx = x + cnt * (1 - i);

            if (0 < nx && nx <= N && 0 < ny && ny <= N)
            {
                if (ny == N && nx == N)
                    return true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x));
    }

    v.push_back(make_pair(0, 0));

    flag = bfs(1, 1);

    if (flag)
        cout << dist << '\n';
    else
        cout << "-1" << '\n';

    return 0;
}
