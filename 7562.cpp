#include <bits/stdc++.h>

using namespace std;

int N, final_x, final_y;
int dist[333][333];
bool check[333][333];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int i, int j) {

	check[i][j] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		if (y == final_y && x == final_x) {
			return;
		}

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !check[ny][nx]) {
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

	int tc, init_x, init_y;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		memset(check, 0, sizeof(check));
		memset(dist, 0, sizeof(dist));

		cin >> N;
		cin >> init_x >> init_y;
		cin >> final_x >> final_y;

		bfs(init_y, init_x);

		cout << dist[final_y][final_x] << '\n';
	}

	return 0;
}