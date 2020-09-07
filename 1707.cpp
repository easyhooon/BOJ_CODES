/*#include <bits/stdc++.h>

using namespace std;
vector <int> a[20001];
int color[20001];

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			//color[next] == 0 �̸� ���� �湮���ߴٴ� ������ �湮����
			dfs(next, 3 - c);
			//�湮���� 0, �湮�ߴµ� �׷��ȣ 1, �湮�ߴµ� �׷��ȣ2
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
					//��� ������ ���ؼ� ���� ���� ���� ������ �̺� �׷����� �ƴϴ�.
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}*/