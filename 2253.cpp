#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
bool check[MAX + 1];
int dist[MAX + 1];
int n, m, jump;

void dfs(int now, int jump, int end)
{
    //재귀로 구현할 수 밖에 없겠는데
    if (now + jump == end)
    {
        if (!check[now + jump])
        {
            // cout << now << ' ' << jump << ' ' << dist[now] << '\n';
            check[now + jump] = true;
            dist[now + jump] = dist[now] + 1;
            // return;
        }
    }

    if (now + jump < end)
    {
        if (!check[now + jump])
        {
            if (jump - 1 <= 0)
            {
                // cout << now << ' ' << jump << ' ' << dist[now] << '\n';
                check[now + jump] = true;
                dist[now + jump] = dist[now] + 1;
                dfs(now + jump, jump + 1, end);
                dfs(now + jump, jump, end);
            }
            else
            {
                // cout << now << ' ' << jump << ' ' << dist[now] << '\n';
                check[now + jump] = true;
                dist[now + jump] = dist[now] + 1;
                dfs(now + jump, jump + 1, end);
                dfs(now + jump, jump, end);
                dfs(now + jump, jump - 1, end);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int flag;
        cin >> flag;
        check[flag] = true;
    }

    jump = 1;

    dist[n] = -1;

    dfs(1, jump, n);

    cout << dist[n] << '\n';

    return 0;
}