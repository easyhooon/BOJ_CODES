#include <bits/stdc++.h>

using namespace std;

/*int n, s, cnt;
int number[21];
bool check[21];

void bfs() {
	check[i][j] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !check[ny][nx]) {
				dist[ny][nx] = dist[y][x] + 1;
				check[ny][nx] = true;

				if (ny == final_y && nx == final_x) {
					return;
				}

				q.push(make_pair(ny, nx));
			}
		}
	}

}*/

/*int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> number[i];

		bfs();

		cout << cnt << '\n';
	}

	return 0;

*/
#include <bits/stdc++.h>

using namespace std;

int n, s, number[20], cnt;

void solve(int index, int sum)
{
	if (sum + number[index] == s)
		++cnt;
	if (index == n - 1)
		return;

	solve(index + 1, sum + number[index]);
	solve(index + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> number[i];

	solve(0, 0);
	cout << cnt;
	return 0;
}