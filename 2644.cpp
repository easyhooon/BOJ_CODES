#include <bits/stdc++.h>

using namespace std;
#define MAX 111

vector<int> v[MAX];
bool check[MAX];
int depth[MAX];
queue<int> q, c;

int bfs(int x, int y)
{
    q.push(x);
    depth[x] = 0;

    check[x] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (f == y)
        {
            return depth[f];
        }
        int v_size = v[f].size();
        for (int i = 0; i < v_size; i++)
        {
            if (check[v[f][i]])
                continue;
            check[v[f][i]] = true;
            q.push(v[f][i]);
            depth[v[f][i]] = depth[f] + 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, m, result;

    cin >> n >> x >> y >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    result = bfs(x, y);

    cout << result << '\n';
}