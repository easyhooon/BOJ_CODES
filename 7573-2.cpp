#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, l, m;

struct Fish
{
    int y, x;
};

Fish fish[MAX + 1];

bool isin(int y, int x)
{
    return 0 < y && y <= n && 0 < x && x <= n;
}

int solve(int idx)
{
    int ans = 0;
    for (int w = 1; w < l / 2; w++)
    {
        int h = l / 2 - w;
        for (int ty = -h; ty <= 0; ty++)
        {
            for (int tx = -w; tx <= 0; tx++)
            {
                int min_y = fish[idx].y + ty;
                int min_x = fish[idx].x + tx;
                int max_y = min_y + h;
                int max_x = min_x + w;
                int cnt = 0;

                if (!isin(min_y, min_x) || !isin(max_y, max_x))
                    continue;
                for (int i = 0; i < m; i++)
                {
                    if (min_y <= fish[i].y && fish[i].y <= max_y && min_x <= fish[i].x && fish[i].x <= max_x)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> m;
    for (int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        fish[i] = {y, x};
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, solve(i));
    }
    cout << ans;
}