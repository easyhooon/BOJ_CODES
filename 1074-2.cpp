#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int cnt;

void Z(int size, int y, int x)
{
    //제일 작은 크기, 2 == (1 << 1)
    if (size == 2)
    {
        if (y == r && x == c)
        {
            cout << cnt << "\n";

            return;
        }
        cnt++;

        if (y == r && x + 1 == c)
        {
            cout << cnt << "\n";

            return;
        }
        cnt++;

        if (y + 1 == r && x == c)
        {
            cout << cnt << "\n";

            return;
        }
        cnt++;

        if (y + 1 == r && x + 1 == c)
        {
            cout << cnt << "\n";

            return;
        }
        cnt++;

        return; //해당 2 * 2 블럭에 R, C가 없을 경우
    }
    //1사분면
    Z(size / 2, y, x);
    //2사분면
    Z(size / 2, y, x + size / 2);
    //3사분면
    Z(size / 2, y + size / 2, x);
    //4사분면
    Z(size / 2, y + size / 2, x + size / 2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    Z(1 << n, 0, 0);

    return 0;
}
