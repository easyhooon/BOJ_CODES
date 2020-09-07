#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX]; //점유하고 있는 노드의 정보의 배열
bool c[MAX]; // 처리 판단

int n, m;

//매칭에 성공한 경우 True , 실패한 경우 False
bool dfs(int x) {
	//연결된 모든 노드에 대해서 들어갈 수 있는지 시도
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//이미 처리한 노드는 더이상 볼 필요가 없음
		if (c[t]) continue;
		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	//한번에 입력을 받게 하는 방법
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++ ) { //최대한 우겨 넣습니다.
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << '\n';
	return 0;
}