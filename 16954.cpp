#include <bits/stdc++.h>

using namespace std;

string s[8];
const int dy[9] = { -1,0,1,1,1,0,-1,-1,0 };
const int dx[9] = { 1,1,1,0,-1,-1,-1,0,0 };
bool check[9][8][8];

bool isin(int y, int x)
{
	return (0 <= y && y < 8 && 0 <= x && x < 8);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; ++i)
		cin >> s[i];

	//pair 확장 
	queue<tuple<int, int, int>> q;
	q.push({ 0,7,0 });
	check[0][7][0] = true;

	int ans = 0;
	while (!q.empty()) {
		int t = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());

		q.pop();

		if (y == 0 && x == 7) ans = 1;


		for (int i = 0; i < 9; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = min(t + 1, 8);

			if (!isin(ny, nx)) continue;

			// 벽이라서 못갈때
			if (ny - t >= 0 && s[ny - t][nx] == '#') continue;

			// 내려올 벽에 닿았을때
			if (ny - t - 1 >= 0 && s[ny - t - 1][nx] == '#') continue;

			if (!check[nt][ny][nx]) {
				check[nt][ny][nx] = true;
				q.push({ nt,ny,nx, });
			}

		}
	}
	if (ans) 
		cout << 1 << "\n";
	else 
		cout << 0 << "\n";

	return 0;
}