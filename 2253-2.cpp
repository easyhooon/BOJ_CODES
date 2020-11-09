#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000;
const int INF = 987654321;
int N, M;
bool success;
bool rock[MAX+1];
int board[MAX+1][250];

int jump(int idx, int len)
{
    //���� ����
    if (idx == N)
    {
        success = true;
        return 0;
    }

    int &result = board[idx][len];

    if (result != -1)
        return result;

    result = INF;

    for (int i = -1; i <= 1; i++)
    {
        //���� �ӵ��� 1 �̻��̰�
        if ((len + i) >= 1)
        {
            int next = idx + (len + i);
            //���� ���� �ִ� ���̰� �� �� �ִ� ���� ���� ����Լ� ȣ��
            if (next <= N && !rock[next])
                result = min(result, 1 + jump(next, (len + i)));
        }
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int num;

        cin >> num;

        rock[num] = true;
    }

    memset(board, -1, sizeof(board));

    int result = jump(1, 0);

    if (success)
        cout << result << "\n";

    else
        cout << -1 << "\n";

    return 0;
}
