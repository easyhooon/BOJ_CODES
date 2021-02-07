#include <bits/stdc++.h>

using namespace std;

const int MAX = 100; //임의의 MAX number

int n, m; //문제의 입력 변수
int arr[MAX+1][MAX+1]; // 배열 선언 
int ans; // 문제의 해답에 해당하는 변수 선언 

//Test Case가 여러개인 경우 초기화 함수가 필요, 그렇지 않을 경우 필요x
void initialize()
{
    ans = 0; //답의 초기화 
    //배열의 초기화
    memset(arr, false, sizeof(arr));
}

//문제의 입력을 받는 함수 
void input()
{
    cin >> n >> m;
    
    //많은 문제가 이차원배열의 입력을 받기 때문에 살려놓았다. 안받으면 뭐 지우면 된다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

//solution에 필요한 함수 구현하는 공간


// 위에서 구현한 함수들을 통해 문제를 직접적으로 풀어내는 함수
// 문제의 요구사항이 간단할 경우 함수를 모듈화하지 않고 solution 내부에서 함수를 구현해도 됨 
void solution()
{
    
}

void solve()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        initialize(); //초기화하고
        input(); //입력을 받고
        solution(); // 푼다

        cout << ans << '\n'; //답을 출력
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
