#include <bits/stdc++.h>

using namespace std;

int N, M,result;
bool check[1111][1111];
int board[1111][1111];
int dist[1111][1111];
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

queue<pair<int, int> > q;

void bfs() {

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		check[y][x] = true;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !check[ny][nx] && board[ny][nx] == 0) {
				dist[ny][nx] = dist[y][x] + 1;
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}
	

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	//너비 , 높이 순으로 너비-> x, 높이 -> y
	cin >> N >> M; //N-> x , M -> y

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			//처음 토마토가 있는 위치 
			if (board[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	int max = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != -1 && !check[i][j]) {
				result = -1;
				cout << result << '\n';
				return 0;
			}
			else if (max < dist[i][j]) {
				max = dist[i][j];
			}
		}
	}

	result = max;

	cout << result << '\n';
	
	return 0;
}

