#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 20001 //V ������ ����
#define MAX_E 300001 //E ������ ����

using namespace std;
int start_node_num, V, E;

typedef struct NODE {
	int end;
	int val;
};

// �� ����� ������ �����ϴ� ���� 
// 0�� �ε����� ������. 
vector<NODE> EDGE_arr[MAX_E];
// ��� ��忡�������� �Ÿ��� �����ϴ� �迭
int dist[MAX_V] = { 0 };

void dijkstra() {
	priority_queue< pair<int, int> > pq;
	pq.push({ 0, start_node_num });

	// ����� �Ÿ� ������ V-1 �� ��ŭ �ϸ� �ȴ�. 
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		// ���� ��忡�� ���� �ֺ��� �ִ� ����� ���� �����Ѵ�. 
		for (int k = 0; k < EDGE_arr[now_node].size(); k++) {
			int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
			int before_val = dist[EDGE_arr[now_node][k].end];

			// ���� ���� ���� ����� ������ ���������� ���� �Ÿ��� ������ �Ÿ��� ���Ͽ�, 
			// ������ ���� �� ũ�� ���� �����Ѵ�.  
			if (new_val < before_val) {
				dist[EDGE_arr[now_node][k].end] = new_val;
				pq.push({ -1 * new_val, EDGE_arr[now_node][k].end });
			}
		}

	}
}

int main() {
	cin >> V >> E >> start_node_num;

	int from, to, val;
	// ���� ���� 
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &val);
		EDGE_arr[from].push_back(NODE{ to, val });
	}

	// �������� �Ÿ� �ʱ�ȭ 
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[start_node_num] = 0;

	// ����-���� �˰������� ���⵵�� O(V*E) �̱� ������, �� ���������� �ʹ� ũ��. 
	// ���ͽ�Ʈ�� �˰������� �����Ѵ�.
	dijkstra();

	// ���� ����Ѵ�. 
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) printf("%d\n", dist[i]);
		else printf("INF\n");
	}

	return 0;
}