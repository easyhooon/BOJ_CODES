#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
int n, l, m, h, w, max_cnt;
char board[MAX + 1][MAX + 1];
bool check[MAX +1][MAX + 1];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool isin(int y, int x)
{
    return (0 < y && y + h <= n && 0 < x && x + w <= n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> m;

    for (int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = '1';
    }

    max_cnt = 0;

    //h 높이  w 너비
    for (h = 1; h < l / 2; h++)
    {
        memset(check, false, sizeof(check)); 
        
        w = l / 2 - h;

        queue<pair<int, int>> q;

        q.push({1, 1});

        check[1][1] = true;

        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;

            q.pop();

            for (int i = 0; i < 2; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (isin(ny, nx) && !check[ny][nx]){
                    int cnt = 0;
                    for(int j = ny; j <= ny + h; j++){
                        for( int k = nx; k <= nx + w; k++){
                            if(board[j][k] == '1'){
                                cnt++;
                            }
                        }      
                    }
                    max_cnt = max(max_cnt, cnt); 
                    check[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }

    cout << max_cnt << '\n';

    return 0;
}