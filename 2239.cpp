#include<bits/stdc++.h>

using namespace std;

const int MAX = 9;
 
int board[MAX][MAX];

//row[i][j] -> i��° �����ٿ� j��� ���ڴ� �̹� �����Ѵ�
bool row[MAX][MAX];

//row�� ���� ���� 
bool col[MAX][MAX];

//9�� �� i��° �簢��  
//square[i][j] -> i��° �簢���� j��� ���ڰ� �ִ�(true)
// 0 1 2
// 3 4 5
// 6 7 8
bool square[MAX][MAX]; 
 
void print()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
 
 
void dfs(int cnt)
{
    int x = cnt / MAX;
    int y = cnt % MAX;
 
    if (cnt == 81)
    {
        print();
        exit(0);
    }
 
    if (board[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;

                dfs(cnt + 1);

                //�ٽ� ���ƿ���(back)
                board[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else dfs(cnt + 1);
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.length(); j++)
        {
            board[i][j] = inp[j] - '0';
            if (board[i][j] != 0)
            {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
            }
        }
    }
 
    dfs(0);

    return 0;
}