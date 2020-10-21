#include <bits/stdc++.h>

using namespace std;

int n;
int check[8][8];
char board[8][8];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

int min_result = INT_MAX;
int max_result = -INT_MAX;

void dfs(int x, int y, int z)
{
    if (x == n - 1 && y == n - 1)
    {
        max_result = max(max_result , z);
        min_result = min(min_result , z);

        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || ny >= n)
            continue;

        if (!check[nx][ny])
        {
            check[nx][ny] = 1;
            if (board[x][y] == '+')
                dfs(nx, ny, z + board[nx][ny] - '0');
            else if (board[x][y] == '-')
                dfs(nx, ny, z - board[nx][ny] + '0');
            else if (board[x][y] == '*')
                dfs(nx, ny, z * (board[nx][ny] - '0'));
            else
                dfs(nx, ny, z);
            check[nx][ny] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, 0, board[0][0] - '0');

    cout << max_result << " " << min_result << '\n';
}