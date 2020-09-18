#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m ;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    //prev_permuation을 통해서 이전 순열 구하기
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "";
        }

        cout << '\n';
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}