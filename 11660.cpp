// #include <bits/stdc++.h>

// //문제 이해 똑바로
// using namespace std;
// typedef long long ll;

// int board[1030][1030];
// ll acc_board[1030][1030];

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m, fy, fx, ly, lx;

//     cin >> n >> m;

//     ll acc = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> board[i][j];
//             acc = acc + board[i][j];
//             acc_board[i][j] = acc;
//         }
//     }

//     for (int i = 1; i <= m; i++)
//     {
//         cin >> fy >> fx >> ly >> lx;

//         if (ly == 1)
//         {
//             cout << acc_board[ly][lx] - acc_board[fy][fx] + board[fy][fx];
//         }

//         if (lx == 1)
//         {
//             cout << acc_board[ly][lx]
//         }
//         else
//             cout << acc_board[ly][lx] - acc_board[ly][lx - 1] - acc_board[ly - 1][lx] + acc_board[ly][lx - 1] << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1025; //ㅇㅇ typedef보다 이거를 지향하라 하더라

int acc_board[MAX][MAX];

int main(void)
{
        ios_base::sync_with_stdio(false);

        cin.tie(NULL);

        int n, m;

        cin >> n >> m;

        for(int i=0; i<n; i++)
                 for (int j = 0; j < n; j++)
                 {
                         int num;
                         cin >> num;
                         //중복으로 뺀 acc_board[i][j]다시 더해줘야함 
                         acc_board[i + 1][j + 1] = acc_board[i + 1][j] + acc_board[i][j + 1] - acc_board[i][j] + num;
                 }

        for (int i = 0; i < m; i++)
        {
                 int fy, fx, ly, lx;
                 cin >> fy >> fx >> ly >> lx;
                 cout << acc_board[ly][lx] - acc_board[fy - 1][lx] - acc_board[ly][fx - 1] + acc_board[fy - 1][fx - 1] << "\n";
        }
        return 0;
}
