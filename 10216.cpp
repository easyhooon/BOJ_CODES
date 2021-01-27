#include <bits/stdc++.h>

using namespace std;

int t, n;
int camp[3000][3];
int check[3000];
vector<vector<int>> v;

int dfs(int x)
{
    int cnt = 1;
    check[x] = 1;

    for (auto a : v[x])
    {
        if (check[a])
            continue;
        cnt += dfs(a);
    }

    return cnt;
}

void initialize()
{
    v.clear();
    memset(check, 0, sizeof(check));
}

void input()
{
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> camp[i][0] >> camp[i][1] >> camp[i][2];
    }
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = camp[i][0] - camp[j][0];
            int y = camp[i][1] - camp[j][1];

            double r = (double)camp[i][2] + (double)camp[j][2];
            double d = sqrt(x * x + y * y);

            if (d <= r)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (check[i])
            continue;

        cnt++;

        for (auto a : v[i])
            dfs(a);
    }

    cout << cnt << '\n';
}

void solve()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        initialize();
        input();
        solution();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
