//이 풀이 틀 상당히 괜찮은거 같다. 일관된 틀 이 틀에 맞춰 풀어보도록 하자.
#include <bits/stdc++.h>

using namespace std;

int player[11][11], ans;
bool check[11];

void initialize()
{
    ans = 0;
    memset(check, false, sizeof(check));
    memset(player, 0, sizeof(player));
}

void input()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> player[i][j];
        }
    }
}

void dfs(int cnt, int sum)
{
    if (cnt == 11)
    {
        if (ans < sum)
            ans = sum;
        return;
    }

    for (int i = 0; i < 11; i++)
    {
        if (player[cnt][i] != 0 && check[i] == false)
        {
            check[i] = true;
            dfs(cnt + 1, sum + player[cnt][i]);
            check[i] = false;
        }
    }
}

void solution()
{
    for (int i = 0; i < 11; i++)
    {
        if (player[0][i] != 0)
        {
            check[i] = true;
            dfs(1, player[0][i]);
            check[i] = false;
        }
    }
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

        cout << ans << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
