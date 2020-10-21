#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1000001;

int t ,n ,cost[MAX]; ;         

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }

        int max_cost = cost[n]; 

        ll max_benefit = 0; 

        for (int i = n - 1; i > 0; i--)
        {
            if (max_cost < cost[i])
                max_cost = cost[i]; //최대 주가 갱신
            else if (max_cost > cost[i])
            {
                max_benefit += (ll)(max_cost - cost[i]); 
            }
            else
                continue; // 값이 같은 경우 pass
        }

        cout << max_benefit << '\n';
    }
}