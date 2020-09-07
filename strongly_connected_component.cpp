#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1001

using namespace std;

int id; 
int d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>>SCC;
stack<int> s;

//DFS는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x) {
	d[x] = x; // 노드마다 고유한 번호를 할당 (자기자신이 부모)
	s.push(x); // 스택에 자기 자신을 삽입

	int parent = d[x];
	//인접한 노드를 하나씩 확인
	for (int i = 0; i < a[x].size(); i++) {
		//y -> 인접한 노드 
		int y = a[x][i];
		//방문하지 않은 이웃 -> 해당 노드로 dfs를 수행
		if (d[y] == 0) parent = min(parent, dfs(y));
		//방문은 하였는데 처리중인 이웃(dfs를 수행중인 이웃)
		//parent값을 처리되고 있는 값과 비교
		else if (!finished[y]) parent = min(parent, d[y]);
	}
	//부모노드가 자기 자신인 경우
	if (parent == d[x]) {
		//scc 객체 생성
		//자기 자신이 나올때까지 뽑음
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			//자기자신 (부모값이 나온경우)이 나온 경우
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	//자신의 부모 값을 반환
	return parent;
}

int main(void) {
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	printf("SCC의 갯수: %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}