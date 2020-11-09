#include <bits/stdc++.h>

using namespace std;

int n, k, ans;

const int MAX = 100000;
int board[MAX+1][2];
bool check[MAX+1][2];
int dx[2] = {1, -1};

bool isin(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[j][i];
        }
    }

    queue<pair<int, int>> q;

    q.push({0, 0});

    check[0][0] = true;
    int Time = 0;

    while (int s = q.size())
    {
        while (s--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x < Time)
                continue;

            for (int i = 0; i < 2; i++)
            {
                int nx = x + dx[i];
                int ny = y;
                if (isin(nx, ny) && board[nx][ny] == 1 && !check[nx][ny])
                {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            int nx = x + k;
            int ny = (y + 1) % 2;

            if (isin(nx, ny) && board[nx][ny] == 1 && !check[nx][ny])
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }

            else if (nx >= n)
                ans = 1;
        }
        Time++;
    }

    ans = ans || check[n - 1][0] || check[n - 1][1];

    cout << ans << '\n';
}

