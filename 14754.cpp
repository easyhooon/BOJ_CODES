//지워야하는 인덱스를 저장해야 예외 없이 정답으로 처리될 것 같음
//아니면 칼럼마다로 분리를 해줘야됨 칼럼의 최댓값이 같을 경우가 현재 고려되지 않고 있음

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll arr[1011][1011];
bool check[1011][1011];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    ll sum = 0;
    ll max_sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    if (n == 1 || m == 1)
    {
        cout << sum << '\n';

        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        ll max_value = 0;
        int max_index = 0;
        for (int j = 1; j <= m; j++)
        {
            if (max_value < arr[i][j])
            {
                max_value = arr[i][j];
                max_index = j;
            }
        }
        check[i][max_index] = true;
        max_sum += max_value;
    }

    for (int i = 1; i <= m; i++)
    {
        int max_index = 0;
        ll max_value = 0;
        for (int j = 1; j <= n; j++)
        {
            if (max_value < arr[j][i])
            {
                max_value = arr[j][i];
                max_index = j;
            }
        }
        if (!check[max_index][i])
        {
            max_sum += max_value;
        }
    }

    ll result = sum - max_sum;

    // cout << sum << '\n';

    // cout << sum_of_s << '\n';

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout << "value: " << *it << '\n';
    // }
    // cout << max_sum << '\n';

    cout << result << '\n';

    return 0;
}