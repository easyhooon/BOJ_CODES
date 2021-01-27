#include <bits/stdc++.h>

using namespace std;

const int MAX = 64 + 1;

int tc, n;
long long cache[10][MAX]; //시작하는 수, 자리수 길이

long long nondecreasingNum(int start, int length)
{
    long long &result = cache[start][length];

    if (result != -1)

        return result;

    //start~9까지 모두 가능
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

        cache[i][1] = 1; //초기값(0~9는 모두 성립)

    for (int i = 0; i < tc; i++)
    {
        cin >> n;

        long long result = 0;
        //0~9로 시작하는 숫자 경우의 수 모두 더한다
        for (int i = 0; i <= 9; i++)
            result += nondecreasingNum(i, n);

        cout << result << '\n';
    }
    return 0;
}
