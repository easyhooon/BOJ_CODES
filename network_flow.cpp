//hard
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 100000000

using namespace std;

int n = 6, result; //최대 유량
int c[MAX][MAX], f[MAX][MAX], d[MAX];
//c 용량 //f 유량 //d 방문 여부
vector<int> a[MAX];

void maxFlow(int start, int end) {
	while (1) {
		// 방문하지 않은 상태로 초기화
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			//bfs를 수행
			int x = q.front();
			q.pop();
			//인접노드를 모두 확인 
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				//방문하지 않은 노드 중에서 용량이 남은 경우
				//용량에서 유량을 뺀 값이 0보다 큰 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; // 경로를 기억합니다.
					//인접 노드가 end값인 경우 , 도착지점인 경우
					if (y == end) break;
				}
			}
		}
		//가능한 모든 경로를 다 찾은 경우
		//너비 우선 탐색을 수행했을 때 도착지 까지 도달을 못 하기 때문에 
		if (d[end] == -1) break;

		//최솟값을 찾아야 하기 때문
		int flow = INF;
		//거꾸로 최소 유량 탐색
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		//최소 유량 만큼 추가합니다
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	printf("%d", result);
}