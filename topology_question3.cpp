#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

//간선 클래스
class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node; // 도착노드
		this->time = time; // 해당 노드를 지나는 비용
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
//result ->현재까지의 비용 (총비용)
vector<Edge> a[MAX]; //출발에서 도착
vector<Edge> b[MAX]; //도착에서 출발

void topologySort() {
	queue<int> q;
	//시작점 노드를 큐에 삽입
	q.push(start);
	//더이상 방문할 노드가 없을때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			//해당 연결된 노드까지의 현재까지의 비용이 해당 간선을 거쳐서 가는 비용보다 작다면 
			if (result[y.node] <= y.time + result[x]) {
				//더 큰 값으로 갱신(임계 경로는 더 큰값이 들어오도록)
				result[y.node] = y.time + result[x];
			}
			//새롭게 정의한 0이 된 정점을 큐에 삽입합니다.
			if (--inDegree[y.node] == 0)
				q.push(y.node);
		}
	}

	//결과를 역추적합니다.
	int count = 0; //  임계 경로에 속한 모든 정점의 개수
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			//최장 경로에 포함되는 간선인지 확인
			if (result[y] - result[x.node] == x.time) {
				count++;
				//큐에는 한 번씩만 담아 추적
				//인덱스의 값이 0인 경우에만
				if (c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	printf("%d\n%d", result[finish], count);
}

int main(void) {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, node, time;
		scanf("%d %d %d", &x, &node, &time);
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(x, time));
		inDegree[node]++;
	}
	scanf("%d %d", &start, &finish);
	topologySort();
}