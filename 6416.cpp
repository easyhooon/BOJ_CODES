#include <bits/stdc++.h>

using namespace std;

int a, b, k = 1;
bool in[110], out[110], check[110];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, k = 1;

    while (true)
    {
        int OUT = 0, cnt = 0;
        while (true)
        {
            cin >> a >> b;
            if (!a && !b)
            {
                if (!cnt || OUT == cnt - 1)
                    cout << "Case " << k++ << " is a tree.\n";
                else
                    cout << "Case " << k++ << " is not a tree.\n";
                break;
            }
            else if (a == -1 && b == -1)
                return 0;
            else
            {
                if (!check[a])
                    cnt++, check[a] = true;
                if (!check[b])
                    cnt++, check[b] = true;
                if (out[b])
                {
                    cout << "Case " << k++ << " is not a tree.\n";
                    cin >> a >> b;
                    while (a | b)
                    {
                        cin >> a >> b;
                    }
                    break;
                }
                in[a] = true;
                out[b] = true;
                OUT++;
            }
        }
    }
    return 0;
}