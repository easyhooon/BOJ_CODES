#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

bool check[MAX];
int dist[MAX];
int f, s, g, u, d;

void bfs(int n) {
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - d >= 1) {
			if (!check[now - d]) {
				check[now - d] = true;
				dist[now - d] = dist[now] + 1;
				q.push(now - d);
			}
		}
		if (now + u <= f) {
			if (!check[now + u]) {
				check[now + u] = true;
				dist[now + u] = dist[now] + 1;
				q.push(now + u);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> f >> s >> g >> u >> d;

	check[s] = true;

	bfs(s);

	//반례
	if (s == g) {
		cout << '0' << '\n';

		return 0;
	}
	//이걸 포함하는 bfs는 못만드나 

	if (dist[g] == 0) {
		cout << "use the stairs" << '\n';
		return 0;
	}

		cout << dist[g] << '\n';

	return 0;
}