#include <bits/stdc++.h>

using namespace std;

int arr[18];
int win[5];
int draw[5];
int lose[5];

int sum(int *arr)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 4; i++)
    {
        memset(arr, 0, sizeof(arr));
        for (int j = 0; j < 18; j++)
        {
            cin >> arr[i];
        }
        for (int k = 0; k < 6; k++)
        {
            win[k] = arr[3 * k];
            draw[k] = arr[1 + 3 * k];
            lose[k] = arr[2 + 3 * k];
        }
        if (sum(win) != sum(lose))
        {
            cout << '0' << " ";
            break;
        }

        cout << '1' << " ";
    }
}