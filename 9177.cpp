#include <bits/stdc++.h>

using namespace std;

bool flag;
int n;
string fir, sec, thr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> fir >> sec >> thr;

        queue<char> q_fir;
        queue<char> q_sec;

        for (int i = 0; i < fir.length(); i++)
            q_fir.push(fir[i]);
        for (int i = 0; i < sec.length(); i++)
            q_sec.push(sec[i]);

        while(!q_fir.empty() && !q_sec.empty())
        {
            
        }

        if (flag)
        {
            cout << "Data set n: yes" << '\n';
        }
        else
        {
            cout << "Data set n: no" << '\n';
        }
    }

    return 0;
}