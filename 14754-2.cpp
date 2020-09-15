#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll arr[1011][1011];

int main()
{
    cin >> n >> m;

    ll sum = 0;

    set<ll> s;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ll max_value = 0;
        for (int j = 1; j <= m; j++)
        {
            max_value = max(max_value, arr[i][j]);
        }
        s.insert(max_value);
    }

    for (int i = 1; i <= m; i++)
    {
        ll max_value = 0;
        for (int j = 1; j <= n; j++)
        {
            max_value = max(max_value, arr[j][i]);
        }
        s.insert(max_value);
    }

    ll sum_of_s = accumulate(s.begin(), s.end(), 0LL);

    ll result = sum - sum_of_s;

    for(auto it = s.begin(); it != s.end(); it++){
    	cout << "value: " << *it << '\n';
    }
    
    cout << result << '\n';

    return 0;
}