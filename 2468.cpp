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

			//�Է� �ִ� ���� ���� 
			if (max < board[i][j]) {
				max = board[i][j];
			}
		}
	}

	//���� ������ �ִ� ���� ����
	int max_components = 0;
	int components = 0;

	//���� 1 ���� �ִ� �Է� ���̱��� �˻�
	for (int l = 0; l < max; l++) {
		//�湮 2���� �迭 �ʱ�ȭ 
		memset(check, 0, sizeof(check));
		
		components = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//���� 1 ���� �Է� �ִ� ���̱��� �˻�
				if (!check[j][k] && board[j][k] > l) {
					//false �϶����� bfs�� ���Ƽ� components�� �ø��� �ȵ����ʳ�
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

