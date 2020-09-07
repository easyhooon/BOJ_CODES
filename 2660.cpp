#include <bits/stdc++.h>
using namespace std;

#define MAX 111

int N;
int MIN = 987654321;
int graph[MAX][MAX];
vector<int> answer;

//k는 경유노드

void floydWarshall(void)
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				//1->1 이런거 어차피 0이라
				if (i == j)
					continue;
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

int main(void)
{
	//시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;

		graph[a][b] = graph[b][a] = 1;
		
	}

	floydWarshall();

	//인덱스 헷갈리지 않기 위함
	vector<int> max_point_v(MAX);

	//회장 후보의 점수 구하기(각 후보가 가지고 있는 점수 중 가장 작은 점수)
	for (int i = 1; i <= N; i++) {
		//후보의 점수 갱신
		int max_point = 0;
		for (int j = 1; j <= N; j++) {
			//각 후보가 가지고 있는 가장 큰 점수 찾기(이 점수가 그 후보의 점수)
			max_point = max(max_point, graph[i][j]);
		}
		//각 후보의 점수를 저장
		max_point_v[i] = max_point;
		//후보들의 점수 중에 가장 작은 점수 찾기(회장 후보의 점수)
		MIN = min(MIN, max_point);
	}

	//회장 후보 찾기(위에서 구한 회장 후보의 점수와 점수가 같은 사람)
	for (int i = 1; i <= N; i++) {
		if (MIN == max_point_v[i])
			answer.push_back(i);
	}

	sort(answer.begin(), answer.end());

	cout << MIN <<" " <<int(answer.size()) << '\n';

	for (int i = 0; i < int(answer.size()); i++)
		cout << answer[i] << " ";

	return 0;
}