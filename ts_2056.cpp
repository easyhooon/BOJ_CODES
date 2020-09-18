//inDegree => 진입차수

#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n, inDegree[MAX], dtime[MAX], result[MAX], sum;

vector<int> v[MAX];

void topologySort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            result[i] = dtime[i];
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = q.front();
        int vsize = v[x].size();
        q.pop();

        for (int i = 0; i < vsize; i++)
        {
            int y = v[x][i];
            result[y] = max(result[y], result[x] + dtime[y]);
            if (--inDegree[y] == 0)
                q.push(y);
        }

    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, result[i]);
    }

    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> dtime[i];

        int num, wnum;
        cin >> num;
        if (num == 0)
            continue;
        else
        {
            for (int j = 0; j < num; j++)
            {
                inDegree[i]++;
                cin >> wnum;
                v[wnum].push_back(i);
                //간선의 방향을 헷갈리지 말자. 입력받은 것이 현재 노드의 선행 노드이다.
            }
        }
    }
    topologySort();

    return 0;
}