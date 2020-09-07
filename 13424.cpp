#include <bits/stdc++.h>
using namespace std;

#define MAX 111
#define INF 987654321

int V, E;
int graph[MAX][MAX];

//k는 경유노드

void floydWarshall(void)
{
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++) {
				//1->1 이런거 어차피 0이라
				//if (i == j)
				//	continue;
				if (i == j || i == k || j == k) continue;
				else if (graph[i][k] && graph[k][j])
					//경로가 존재한다면 true 아니면 false
				{
					if (graph[i][j] == 0)
						//한번엔 못가도 경유노드를 거쳐 탐색이 가능할때
						graph[i][j] = graph[i][k] + graph[k][j];

					else
						//핵심! 더 빠른 경로로 갱신
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

				}
			}
}

//코드에 뭐가 문제인지 모르겟다.
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, c; //n:테스트 케이스 , m = 모임에 참여하는 친구의 수

	cin >> n;

	while (n--) {

		cin >> V >> E;

		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {

				if (i == j) graph[i][j] = 0;
				else graph[i][j] = INF;
			}
		}

		for (int i = 0; i < E; i++)
		{
			cin >> a >> b >> c;

			graph[a][b] = c;
			graph[b][a] = c;

		}

		cin >> m;

		vector<int> input(MAX);

		for (int x = 1; x <= m; x++) {
			cin >> input[x];
		}

		floydWarshall();

		/*int min_sum = INF;

		vector <int> room_sum;
		vector <int> ans_room;

		room_sum.push_back(0);


		for (int i = 1; i <= V; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				if (i == input[j]) continue;

				sum += graph[i][input[j]];

			}
			room_sum.push_back(sum);
			min_sum = min(min_sum, sum);
		}

		for (int j = 1; j <= V; j++) {
			if (min_sum == room_sum[j])
				ans_room.push_back(j);
		}
		sort(ans_room.begin(), ans_room.end());
		*/

		int min_sum = INF;
		int min_room = 0;

		for (int i = 1; i <= V; i++) { //방 번호

			int sum = 0;
			for (int j = 1; j <= m; j++) {//모임 참석 친구들
				sum += graph[i][input[j]];
			}

			if (sum < min_sum) {
				min_sum = sum;
				min_room = i;
			}
		}

		cout << min_room << '\n';
	}

	return 0;
}