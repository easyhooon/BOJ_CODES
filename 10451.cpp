#include <bits/stdc++.h>

using namespace std;

const int MAX = 1100;
vector<int> v[MAX];
bool check[MAX];

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dfs(y);
	}

}

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		memset(check, 0, sizeof(check));
		memset(v, 0, sizeof(v));
		int m;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int l;
			scanf("%d", &l);
			v[i].push_back(l);
		}

		int components = 0;

		for (int j = 1; j <= m; j++) {
			if (check[j] == false)
			{
				dfs(j);
				components++;
			}
		}
		printf("%d\n", components);
	}
}
