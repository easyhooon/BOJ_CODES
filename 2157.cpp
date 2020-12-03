
#include <bits/stdc++.h>

using namespace std;

const int MAX = 300;
const int INF = 987654321;
int n, m, k;
int dp[MAX + 1][MAX + 1];    //dp[i][j]-> i->j로 갈때 기내식 점수
int visit[MAX + 1][MAX + 1]; //cnt[i][j] -> i번 도시를 j번 방문

int maxScore(int num, int visit_cnt)
{
    if (visit_cnt == m && num != n)
        return -INF;

    if (num == n)
        return 0;

    int &result = visit[num][visit_cnt];
    if (result != -1)
        return result;

    result = 0;

    for (int j = num + 1; j <= n; j++)
        if (dp[num][j])
            result = max(result, dp[num][j] + maxScore(j, visit_cnt + 1));

    return result;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
        {
            dp[a][b] = max(dp[a][b], c);
        }
    }
    memset(visit, -1, sizeof(visit));

    cout << maxScore(1,1) << '\n';

    return 0;
}
