// #include <bits/stdc++.h>

// using namespace std;

// #define MAX_VALUE 100001

// int n, result;

// vector<int> tr[MAX_VALUE];
// vector<int> ans;

// bool visit[MAX_VALUE];
// int comp[MAX_VALUE];


// void dfs(int v)
// {
//     ans.push_back(v);

//     visit[v] = true;

//     for (int i = 0; i <= tr[v].size(); i++)
//     {
//         int next = tr[v][i];
//         if (visit[next] == false)
//             dfs(tr[v][i]); 
//     }
// }


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int x, y;

//         cin >> x >> y;

//         tr[x].push_back(y);
//         tr[y].push_back(x);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cin >> comp[i];
//     }

//     dfs(1);

//     for (int i = 0; i < n; i++)
//     {
//         if(comp[i] != ans[i])
//             cout << '0' << '\n';
//             return 0;
//     }

//      cout << '1' << '\n';  

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int n, a[MAX + 1];
bool visit[MAX + 1];
int idx = 1;
bool suc;
vector<int> e[MAX+1];

void dfs(int dep, int now) {
	if (idx == n) {
		suc = true;
		return;
	}
	if (visit[now]) return;
	visit[now] = true;

	for (int i = 0; i < e[now].size(); i++) {
		int next = e[now][i];

		if (!visit[next]) {
			if (next == a[idx]) {
				idx++;
				dfs(dep+1, next);
				i = -1;
			}
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0, a, b; i < n-1; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dfs(0, 1);

	if (suc) cout << 1 << '\n';
	else cout << 0 << '\n';
	
	return 0;
}