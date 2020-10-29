#include <bits/stdc++.h>

using namespace std;

int N, x, y, ny, nx, cnt;
bool flag;
int board[65][65];
int check[65][65];
//메모리를 아끼자고 중복체크 배열을 없애면 안되지 큐에 계속해서 중복 pair가 쌓임!

queue<pair<int, int>> q;

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

            if (0 < nx && nx <= N && 0 < ny && ny <= N && !check[ny][nx])
            {
                if (ny == N && nx == N)
                    return true;
                check[ny][nx] = true;
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

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    q.push(make_pair(1, 1));
    check[1][1] = true;

    flag = bfs(1, 1);

    if (flag)
        cout << "HaruHaru" << '\n';
    else
        cout << "Hing" << '\n';

    return 0;
}
