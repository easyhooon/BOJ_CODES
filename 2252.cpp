#include <bits/stdc++.h>

using namespace std;

const int MAX = 32001;
//#define MAX 32001

int n, m, inDegree[MAX], result[MAX];
vector<int> v[MAX];

void topologySort()
{
    queue<int> q; //queue는 무조건 지역변수로

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int x = q.front();
        q.pop();

        result[i] = x;
        for (int j = 0; j < v[x].size(); j++)
        {
            int y = v[x][j];
            if (--inDegree[y] == 0)
                q.push(y);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
}

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
}