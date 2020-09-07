#include <bits/stdc++.h>

//bfs 아님 
using namespace std;

int N, M, K;
//int dist[16][16];
//bool check[16][16];
int dp[16][16];
//int dx[2] = { 1, 0};
//int dy[2] = { 0, 1};

//void bfs(int i, int j) {
//	check[i][j] = true;
//
//	queue<pair<int, int> > q;
//	q.push(make_pair(i, j));
//
//	while (!q.empty()) {
//		int x = q.front().second;
//		int y = q.front().first;
//
//		q.pop();
//
//		for (int k = 0; k < 2; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (1 <= nx && nx <= M && 1 <= ny && ny <= N && board[ny][nx] != 1 && !check[ny][nx]) {
//				dist[ny][nx] = dist[y][x] + 1;
//				check[ny][nx] = true;
//				q.push(make_pair(ny, nx));
//			}
//		}
//	}
//
//}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q, r; //몫, 나머지 

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == 1 || j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	////지나갈 수 없는 칸을 1로 채우자 

	if(K != 0){
		q = K / M;
		r = K % M;

		//q에는 1을 더해줘야함 몫이 1이면, 2번째 줄이기 때문


		//이로써 o칸은 (q, r)이 되었음 

		//나머지가 0이면...?
		if (r != 0) {
			q = q + 1;
		}
		else {
			r = M;

		}

		for (int i = q + 1; i <= N; i++) {
			dp[i][r] = 1;
		}

		for (int j = r + 1; j <= M; j++) {
			dp[q][j] = 1;
		}

		for (int i = q + 1; i <= N; i++) {
			for (int j = r + 1; j <= M; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[q][r] * dp[N][M] << '\n';
	}
	else {

		cout << dp[N][M] << '\n';
	}

	return 0;
}