#include <bits/stdc++.h>

using namespace std;

int N, M;
bool check[111][111];
int board[111][111];
int dx[8] = { 0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = { -1, 0, 1, 0, -1, 1, -1, 1};

void bfs(int i, int j) {
	check[i][j] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !check[ny][nx] && board[ny][nx]) {
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int components = 0;


	while (true) {
		//�ʺ� , ���� ������ �ʺ�-> x, ���� -> y
		cin >> N >> M; //N-> x , M -> y

		if (N == 0 && M == 0) break;

		for (int i = 0; i < M; i++) { 
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		//�湮 �迭 �ʱ�ȭ
		memset(check, 0, sizeof(check));

		//�� ���� �ʱ�ȭ
		components = 0;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				//���� 1 ���� �Է� �ִ� ���̱��� �˻�
				if (board[j][k] && !check[j][k]) {
					//false �϶����� bfs�� ���Ƽ� components�� �ø��� �ȵ����ʳ�
					bfs(j, k);
					components++;
				}
			}
		}
		cout << components << '\n';
	}
	

	return 0;
}

