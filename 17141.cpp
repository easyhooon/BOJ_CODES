#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coord;
const int INF = 0x3f3f3f3f; //INFINITY

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int board[55][55], n, m, empty_count;
int ans = INF;
int vsize;

vector<coord> virus;

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

int bfs(int *arr)
{
    bool visit[55][55] = {false};
    int min_time = 0, left = empty_count;

    queue<coord> q;

    for (int i = 0; i < vsize; i++)
    {
        if (arr[i])
        {
            int &y = virus[i].first, &x = virus[i].second;
            left--;
            q.push(virus[i]);
            visit[y][x] = true;
        }
    }

    while (!q.empty() && left)
    {
        int qsize = q.size();

        for (int a = 0; a < qsize; a++)
        {

            auto &top = q.front();
            auto &cy = top.first, &cx = top.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i], nx = cx + dx[i];
                if (isin(ny, nx) && board[ny][nx] == 0 && !visit[ny][nx])
                {
                    visit[ny][nx] = true;
                    q.push(coord(ny, nx));
                    left--;
                }
            }
        }
        if (!q.empty())
            min_time++;
    }

    return (left == 0 ? min_time : INF);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                empty_count++;
            }
            else if (board[i][j] == 2)
            {
                board[i][j] = 0;
                empty_count++;
                virus.push_back({i, j});
            }
        }
    }
    vsize = virus.size();

    int arr[vsize] = {0}; // 무시하셈 실행은 됨

    for (int i = 0; i < m; i++)
        arr[i] = 1;

    do
    {
        ans = min(ans, bfs(arr));
    } while (prev_permutation(arr, arr + vsize));

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}