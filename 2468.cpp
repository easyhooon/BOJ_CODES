#include <bits/stdc++.h>

using namespace std;

int N;
bool check[111][111];
int board[111][111];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int i, int j, int height) {
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
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !check[ny][nx] && board[ny][nx] > height) {
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			//입력 최대 높이 갱신 
			if (max < board[i][j]) {
				max = board[i][j];
			}
		}
	}

	//안전 영역의 최대 갯수 갱신
	int max_components = 0;
	int components = 0;

	//높이 1 부터 최대 입력 높이까지 검사
	for (int l = 0; l < max; l++) {
		//방문 2차원 배열 초기화 
		memset(check, 0, sizeof(check));
		
		components = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//높이 1 부터 입력 최대 높이까지 검사
				if (!check[j][k] && board[j][k] > l) {
					//false 일때마다 bfs를 돌아서 components가 올르면 안되지않나
					bfs(j, k, l);
					components++;
				}
			}
		}
		if (max_components < components) max_components = components;				
	}

	cout << max_components << '\n';

	return 0;
}

