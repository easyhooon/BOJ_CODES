/*#include <bits/stdc++.h>

using namespace std;
vector <int> a[20001];
int color[20001];

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			//color[next] == 0 이면 아직 방문안했다는 것으로 방문해줌
			dfs(next, 3 - c);
			//방문안함 0, 방문했는데 그룹번호 1, 방문했는데 그룹번호2
			//1->2 , 2->1 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	scanf("%d\n", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}

		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < a[i].size(); k++) {
				int j = a[i][k];
				if (color[i] == color[j]) {
					ok = false;
					//모든 정점에 대해서 색이 같은 것이 있으면 이분 그래프가 아니다.
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}*/