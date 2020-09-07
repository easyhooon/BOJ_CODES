/*접근 과정
1. 소수
한 자리 숫자를 바꿔서 다음 숫자를 만들었을 때 
매번 소수인지를 확인하지 말고 에라토스테네스의 체를 이용해서 9999까지 소수를 미리 구해줍니다.

2. BFS
A에서 B를 만들 수 있는 최소 변경 횟수를 구하는 문제입니다.
각 소수를 정점, 변경 횟수를 거리로 보면 그래프로 설계할 수 있습니다.
모든 간선의 가중치가 같을 때 BFS는 최단 경로를 찾아줍니다.
따라서, BFS를 이용해서 A에서 B로 가는 최소 변경 횟수를 찾습니다.

3. 시간 복잡도 계산
1) O(n) = 4자리 수 모두 탐색

n(1000 <= n <= 10000) 4자리 수의 개수 이기 때문에 
O(n)은 O(10000) 문제의 시간 제한이 2초 이기 때문에 시간안에 풀 수 있습니다.*/

#include <iostream>
#include <cstring>
#include <queue>
#include <string>

#define max_int 10001
using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: BFS, 에라토스테네스의 체
//사용한 자료구조: 배열

int n, start_node, end_node;
bool prime[max_int];
int check[max_int];

// 에라토스테네스의 체로 9999까지 소수를 구해줍니다.
void eratos() {
	for (int i = 2; i*i < max_int; i++) {
		for (int j = i * i; j < max_int; j += i) {
			prime[j] = false;
		}
	}
}

// 4자리 문자열을 정수로 변환합니다.
int to_int(string num) {
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		ret = ret * 10 + (num[i] - '0');
	}

	return ret;
}

// BFS 수행
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		// 맨 앞자리 부터 4자리 검사
		for (int i = 0; i < 4; i++) {
			string node_s = to_string(node);
			// 모든 자리를 0~9로 변환해봅니다.
			for (int j = 0; j < 10; j++) {
				node_s[i] = j + '0';
				int next = to_int(node_s);
				// 다음 이동하려는 숫자가 4자리 수이고, 소수이며, 방문하지 않았다면 큐에 넣어줍니다.
				if (next >= 1000 && prime[next] == true && check[next] == -1) {
					check[next] = check[node] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	// 1. 에라토스테네스의 체를 사용해서 9999까지 소수를 모두 표시해 놓는다.
	memset(prime, true, sizeof(prime));
	eratos();

	scanf("%d", &n);

	while (n--) {
		// 2. 초기화
		memset(check, -1, sizeof(check));

		scanf("%d %d", &start_node, &end_node);

		// 3. BFS 수행
		bfs(start_node);

		// 4. 출력
		// 1) 만약 목표 숫자로 도달 했다면 거리 출력
		if (check[end_node] != -1) {
			printf("%d\n", check[end_node]);
		}
		// 2) 만들 수 없는 숫자라면 Impossible 출력
		else {
			printf("Impossible\n");
		}
	}
}
