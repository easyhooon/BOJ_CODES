// 너비를 우선-> 시작점을 기준으로 가까운 것 위주로 먼저 탐색

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //checked -> 방문을 하였다.
vector<int> a[8]; //8개의 벡터가 들어갈 수 있는 배열(각 노드의 인덱스를 1부터 처리)

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			//q에서 꺼낸 원소와 인접한 노드들을 전부 방문
			int y = a[x][i];
			if (!c[y]) {
				//방문을 하지 않았다면
				q.push(y);
				//담아줌
				c[y] = true;
				//방문하였다.
			}
		}
	}
}

int main(void) {
	//1과 2을 연결
	a[1].push_back(2);
	a[2].push_back(1);
	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);
	//2와 3을 연결
	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	//printf("%d",a[1].size()); -> 2
	bfs(1);
	return 0;
}