#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int stat[MAX][3];
int d[MAX]; //점유하고 있는 노드의 정보의 배열
bool c[MAX]; // 처리 판단

int n;

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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++){
			if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]){
				a[i].push_back(j);
			}else if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
				a[i].push_back(j);
			}else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]) {
				a[j].push_back(i);
			}
		}
	}
	int count = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) count++;

		}
	}
	printf("%d\n", n - count);
	return 0;
}