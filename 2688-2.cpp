#include <bits/stdc++.h>

using namespace std;

const int MAX = 64 + 1;

int tc, n;
long long cache[10][MAX]; //�����ϴ� ��, �ڸ��� ����

long long nondecreasingNum(int start, int length)
{
    long long &result = cache[start][length];

    if (result != -1)

        return result;

    //start~9���� ��� ����
    result = nondecreasingNum(start, length - 1);

    for (int num = start + 1; num <= 9; num++)
        result += nondecreasingNum(num, length - 1);

    return result;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < 10; i++)

        cache[i][1] = 1; //�ʱⰪ(0~9�� ��� ����)

    for (int i = 0; i < tc; i++)
    {
        cin >> n;

        long long result = 0;
        //0~9�� �����ϴ� ���� ����� �� ��� ���Ѵ�
        for (int i = 0; i <= 9; i++)
            result += nondecreasingNum(i, n);

        cout << result << '\n';
    }
    return 0;
}
