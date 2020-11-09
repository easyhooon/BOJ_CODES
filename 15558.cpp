#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int d1[MAX + 1];
int d2[MAX + 1];
bool check1[MAX+1];
bool check2[MAX+1];

int n, k;
string temp1, temp2;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<pair<int, int>, int>> q;

    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));

    cin >> n >> k;

    cin >> temp1;

    for (int i = 0; i < n; i++)
    {
        d1[i + 1] = temp1[i] - '0';
    }

    cin >> temp2;

    for (int i = 0; i < n; i++)
    {
        d2[i + 1] = temp2[i] - '0';
    }

    q.push(make_pair(make_pair(1, 1), 0));

    d1[1] = 0;
    check1[1] = true;

    //현재 d1에 있는지 d2에 있는지를 구분

    while (!q.empty())
    {
        int now = q.front().first.first;
        int line = q.front().first.second;
        int Time = q.front().second;

        cout << now << ' ' << line << ' ' << Time << '\n';

        q.pop();

        if (now >= n)
        {
            cout << '1' << '\n';
            return 0;
        } 

        if (Time >= n) break;

        //현재 위치한 줄을 판단
        if (line == 1)
        {
            if (now + 1 > Time && !check1[now+1])
            {
                if (d1[now + 1] != 0 && !check1[now + 1])
                {
                    check1[now+1] = true;
                    d1[now + 1] = d1[now] + 1;
                    q.push(make_pair(make_pair(now + 1, 1), Time + 1));
                }
            }

            if (now - 1 > Time)
            {
                if (d1[now - 1] != 0 && !check1[now - 1])
                {
                    check1[now -1] = true;
                    d1[now - 1] = d1[now] + 1;
                    q.push(make_pair(make_pair(now - 1, 1), Time + 1));
                }
            }

            if (now + k > Time)
            {
                if (d2[now + k] != 0 && !check2[now + k])
                {
                    check2[now + k] = true;
                    d2[now + k] = d1[now] + 1;
                    q.push(make_pair(make_pair(now + k, 2), Time + 1));
                }
            }
        }

        if (line == 2)
        {
            if (now + 1 > Time)
            {
                if (d2[now + 1] != 0 && !check2[now+1])
                {
                    check2[now+1] = true;
                    d2[now + 1] = d2[now] + 1;
                    q.push(make_pair(make_pair(now + 1, 2), Time + 1));
                }
            }

            if (now - 1 > Time)
            {
                if (d2[now - 1] != 0 && !check2[now - 1])
                {
                    check2[now -1] = true;
                    d2[now - 1] = d2[now] + 1;
                    q.push(make_pair(make_pair(now - 1, 2), Time + 1));
                }
            }

            if (now + k > Time)
            {
                if (d1[now + k] != 0 && !check1[now + k])
                {
                    check1[now + k] = true;
                    d1[now + k] = d2[now] + 1;
                    q.push(make_pair(make_pair(now + k, 1), Time + 1));
                }
            }
        }
    }

    cout << '0' << '\n';

    return 0;
}
