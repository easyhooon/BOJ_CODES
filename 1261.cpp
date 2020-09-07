/*#include <bits/stdc++.h>

using namespace std;
int d[111][111];
int board[111][111];

int n, m;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			d[i][j] = -1; // �� �׳� �������� �ʾҴ� ��� ���� ����ϴ� ���� check�� dist�� ��ģ�� 
		}
	}
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_queue;
	q.push(make_pair(0, 0));

	d[0][0] = 0; // ���� �ʱ�ȭ�� ���⼭ ���� 

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] == -1) {
					if (board[nx][ny] == 0) {
						d[nx][ny] = d[x][y];
						q.push(make_pair(nx, ny));
					}
					else {
						d[nx][ny] = d[x][y] + 1;
						next_queue.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (q.empty()) {
			q = next_queue;
			next_queue = queue<pair<int, int>>();
		}
	}
	printf("%d\n", d[n - 1][m - 1]);

	return 0;
}*/