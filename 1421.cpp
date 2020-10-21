#include<bits/stdc++.h>
using namespace std;

int tree[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, w;
    
    cin >> n >> c >> w;

    int max_len = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> tree[i];
        if (max_len < tree[i])
            max_len = tree[i];
    }
    int max_result = 0;

    for (int i = 1; i <= max_len; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (tree[j] >= i) //더 작으면 자를 수도 없고 아예 팔수가없는거니깐 제외
            {
                int piece, div;
                piece = tree[j] / i; 
                if (tree[j] % i == 0)
                    div = tree[j] / i - 1; 
                else
                    div = tree[j] / i;
 
                if (piece * w*i - div * c > 0)
                    sum += piece * w*i - div * c;
            }
        }
        max_result = max(max_result, sum);
    }
   
   cout << max_result << '\n';
 
}
