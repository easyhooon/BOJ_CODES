//hard
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> a[7]; // 간선 정보
int d[7]; // 최소비용

//pq에다가는 음수붙혀서 d에는 양수로 넣어줌
void dijkstra(int start) {
	d[start] = 0; // 자기 자신이므로
	priority_queue<pair<int, int>> pq; // (최대)힙 구조.
	pq.push(make_pair(start, 0));
	//가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty()) {
		int current = pq.top().first; 
		//짧은 것이 먼저 오도록 음수화(-)합니다.
		//우선순위 큐는 가장 큰 값이 top에 위치하므로 
		//이미 음수화를 하여 저장되어있다고 가정
		int distance = -pq.top().second;
		//양수로 출력됨 
		//printf("%d ", distance);
		//printf("\n");
		//가장 비용이 적은 노드가 실질적으로 가장 큰값으로 큐에 저장
		//큐에 최상단에 가장 비용이 적은 노드가 담겨지게 됨
		pq.pop();
		//최단 거리가 아닌 경우 스킵
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = a[current][i].first;
			//선택된 노드를 인접 노드로 거쳐서 가는 비용
			//선택된 노드까지 가는 최소비용 + 선택된 노드를 거쳐서 인접노드로 가는 비용
			//양수 더하기 양수 
			int nextDistance = distance + a[current][i].second;
			//printf("%d ", nextDistance);
			//기존의 최소 비용보다 더 저렴하면 교체합니다.
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
				printf("%d ", -nextDistance);
				//printf("%d ", nextDistance);
			}
		}
	}
}

int main(void) {
	//기본적으로 연결되지 않은 경우 비용은 무한
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(2, 2));

	//printf("%d ", a[1][0].first);

	dijkstra(1);

	//결과를 출력합니다.
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}