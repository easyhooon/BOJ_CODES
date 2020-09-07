#include <bits/stdc++.h>

//시작점과 끝점이 정해져있지 않음 내가 정해야 함.
//hard
using namespace std;

int N, M;
int dist[100][100];
bool check[100][100];
int maze[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int i, int j) {
	check[i][j] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1 && !check[ny][nx]) {
				dist[ny][nx] = dist[y][x] + 1;
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string arr;
		cin >> arr;
		for (int j = 0; j < M; j++) {
			if (arr[j] == 'W') maze[i][j] = 0;
			else maze[i][j] = 1;
		}
	}

	bfs(0, 0);
	printf("%d\n", dist[N - 1][M - 1] + 1);

	return 0;
}