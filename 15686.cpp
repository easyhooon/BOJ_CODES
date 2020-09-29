//bfs아님
//메모리 초과한 코드랑 같이 블로그에 올릴 것
//cout.tie(null)도 해줘야지?
//queue에는 왜 clear가 없을까?
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coord;

const int INF = 0x3f3f3f3f;

int board[51][51], n, m, sum, cnt, dist;
int ans = INF;
int csize, hsize;

vector<coord> chicken;
vector<coord> home;


int bf(int *arr)
{
    queue<coord> cq; //치킨 큐
    queue<coord> temp; //임시 큐
    //큐 초기화!
    // while(!cq.empty()){
    //     cq.pop();
    // }
    //전역으로 빼지 말고 안에 넣으면 됨

    sum = 0;

    for (int i = 0; i < csize; i++)
    {
        if (arr[i])
        {
            cq.push(chicken[i]);
        }
    }

    for (int i = 0; i < hsize; i++)
    {
        int hy = home[i].first;
        int hx = home[i].second;

        cnt = INF;

        while (!cq.empty())
        {
            auto &ctop = cq.front();
            int cy = ctop.first, cx = ctop.second;
            //cout << cy << " " << cx << '\n';
            temp.push({cy, cx});
            cq.pop();

            dist = abs(cy - hy) + abs(cx - hx);
            if (cnt > dist)
                cnt = dist;
        }
        sum += cnt;
        cq = temp;

        while(!temp.empty()){
            temp.pop();
        }
        //cout << temp.size() << '\n';
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                home.push_back({i, j});

            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    csize = chicken.size();
    hsize = home.size();

    int arr[csize] = {0}; // 무시하셈 실행은 됨

    for (int i = 0; i < m; i++)
        arr[i] = 1;

    do
    {
        ans = min(ans, bf(arr));
    } while (prev_permutation(arr, arr + csize));

    cout << ans << '\n';

    return 0;
}