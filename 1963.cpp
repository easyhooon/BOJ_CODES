/*���� ����
1. �Ҽ�
�� �ڸ� ���ڸ� �ٲ㼭 ���� ���ڸ� ������� �� 
�Ź� �Ҽ������� Ȯ������ ���� �����佺�׳׽��� ü�� �̿��ؼ� 9999���� �Ҽ��� �̸� �����ݴϴ�.

2. BFS
A���� B�� ���� �� �ִ� �ּ� ���� Ƚ���� ���ϴ� �����Դϴ�.
�� �Ҽ��� ����, ���� Ƚ���� �Ÿ��� ���� �׷����� ������ �� �ֽ��ϴ�.
��� ������ ����ġ�� ���� �� BFS�� �ִ� ��θ� ã���ݴϴ�.
����, BFS�� �̿��ؼ� A���� B�� ���� �ּ� ���� Ƚ���� ã���ϴ�.

3. �ð� ���⵵ ���
1) O(n) = 4�ڸ� �� ��� Ž��

n(1000 <= n <= 10000) 4�ڸ� ���� ���� �̱� ������ 
O(n)�� O(10000) ������ �ð� ������ 2�� �̱� ������ �ð��ȿ� Ǯ �� �ֽ��ϴ�.*/

#include <iostream>
#include <cstring>
#include <queue>
#include <string>

#define max_int 10001
using namespace std;

//�ð� ���⵵: O(n)
//���� ���⵵: O(n)
//����� �˰���: BFS, �����佺�׳׽��� ü
//����� �ڷᱸ��: �迭

int n, start_node, end_node;
bool prime[max_int];
int check[max_int];

// �����佺�׳׽��� ü�� 9999���� �Ҽ��� �����ݴϴ�.
void eratos() {
	for (int i = 2; i*i < max_int; i++) {
		for (int j = i * i; j < max_int; j += i) {
			prime[j] = false;
		}
	}
}

// 4�ڸ� ���ڿ��� ������ ��ȯ�մϴ�.
int to_int(string num) {
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		ret = ret * 10 + (num[i] - '0');
	}

	return ret;
}

// BFS ����
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		// �� ���ڸ� ���� 4�ڸ� �˻�
		for (int i = 0; i < 4; i++) {
			string node_s = to_string(node);
			// ��� �ڸ��� 0~9�� ��ȯ�غ��ϴ�.
			for (int j = 0; j < 10; j++) {
				node_s[i] = j + '0';
				int next = to_int(node_s);
				// ���� �̵��Ϸ��� ���ڰ� 4�ڸ� ���̰�, �Ҽ��̸�, �湮���� �ʾҴٸ� ť�� �־��ݴϴ�.
				if (next >= 1000 && prime[next] == true && check[next] == -1) {
					check[next] = check[node] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	// 1. �����佺�׳׽��� ü�� ����ؼ� 9999���� �Ҽ��� ��� ǥ���� ���´�.
	memset(prime, true, sizeof(prime));
	eratos();

	scanf("%d", &n);

	while (n--) {
		// 2. �ʱ�ȭ
		memset(check, -1, sizeof(check));

		scanf("%d %d", &start_node, &end_node);

		// 3. BFS ����
		bfs(start_node);

		// 4. ���
		// 1) ���� ��ǥ ���ڷ� ���� �ߴٸ� �Ÿ� ���
		if (check[end_node] != -1) {
			printf("%d\n", check[end_node]);
		}
		// 2) ���� �� ���� ���ڶ�� Impossible ���
		else {
			printf("Impossible\n");
		}
	}
}
