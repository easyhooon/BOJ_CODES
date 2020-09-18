#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> v(8);
    set<string> s;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    v.resize(n);
    sort(v.begin(), v.end(), greater<int>());

    //prev_permuation을 통해서 이전 순열 구하기
    do
    {
        string temp = "";
        for (int i = 0; i < m; i++)
        {
            if(i != m-1){
                temp += to_string(v[i]);
                temp += " ";
            }
            else temp += to_string(v[i]);
        }
        s.insert(temp);

    } while (prev_permutation(v.begin(), v.end()));

    set<string>::iterator iter;

    for(iter = s.begin(); iter !=s.end(); iter++){
        cout << *iter <<'\n';
    }

    return 0;
}