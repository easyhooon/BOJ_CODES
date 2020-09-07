#include <bits/stdc++.h>

#define MAX 987654321

//앞으로 다익스트라의 틀
using namespace std;
vector<vector<pair<int, int>>>adj;

int n, m, x;

typedef pair <int, int> node;

struct cmp {
	bool operator()(node x, node y) {
		return x.second > y.second;
	}
};

void dijkstra(int x) {
	priority_queue<node, vector<node>, cmp> pq;
	vector<int> dist(n + 1, MAX);
	dist[x] = 0;
	pq.push(make_pair(x, 0));
	for (int i = 1; i <= n; i++) {
		if (i != x) pq.push(make_pair(i, MAX));
	}

	while (!pq.empty()) {
		int u = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf(dist[i] == MAX ? "INF\n" : "%d\n", dist[i]);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	dijkstra(x);
}