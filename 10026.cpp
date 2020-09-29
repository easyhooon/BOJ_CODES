#include <bits/stdc++.h>

using namespace std;

//R = 0, G = 1, B = 2

int n, cnt;
bool check[111][111];
int board[111][111];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int i, int j, int flag)
{
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        check[y][x] = true;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (!check[ny][nx] && board[ny][nx] == flag)
                {
                    check[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

 void search(int flag) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] == false && board[i][j] == flag){
                bfs(i, j, flag);
                cnt++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char input;
            cin >> input;

            if (input == 'R')
                board[i][j] = 0;
            else if (input == 'G')
                board[i][j] = 1;
            else
                board[i][j] = 2;
        }
    }

    for(int i = 0; i < 3; i++){
        memset(check, 0, sizeof(check));
        search(i);
    }
         
    cout << cnt << ' ';

     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] == 1)
                board[i][j] = 0;
        }
    }

    cnt = 0;

    for(int i = 0; i < 3; i++){
        if(i == 1)
            continue;
        memset(check, 0, sizeof(check));
        search(i);
    }

    cout << cnt << '\n';

    return 0;
}
