#include <bits/stdc++.h>

using namespace std;
int n, k, ans;
int board[100010][2];
bool check[100010][2];
int dx[2] = {1, -1};
int dy[2] = {0, 0};
string temp1;
string temp2;

bool isin(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < 2);
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cin >> temp1;

    cin >> temp2;

    for (int i = 0; i < n; i++)
    {
        board[i][0] = temp1[i] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        board[i][1] = temp2[i] - '0';
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
                int ny = y + dy[i];
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

    if (ans)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}