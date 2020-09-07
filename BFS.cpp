// �ʺ� �켱-> �������� �������� ����� �� ���ַ� ���� Ž��

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //checked -> �湮�� �Ͽ���.
vector<int> a[8]; //8���� ���Ͱ� �� �� �ִ� �迭(�� ����� �ε����� 1���� ó��)

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			//q���� ���� ���ҿ� ������ ������ ���� �湮
			int y = a[x][i];
			if (!c[y]) {
				//�湮�� ���� �ʾҴٸ�
				q.push(y);
				//�����
				c[y] = true;
				//�湮�Ͽ���.
			}
		}
	}
}

int main(void) {
	//1�� 2�� ����
	a[1].push_back(2);
	a[2].push_back(1);
	//1�� 3�� ����
	a[1].push_back(3);
	a[3].push_back(1);
	//2�� 3�� ����
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