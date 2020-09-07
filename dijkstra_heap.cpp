//hard
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> a[7]; // ���� ����
int d[7]; // �ּҺ��

//pq���ٰ��� ���������� d���� ����� �־���
void dijkstra(int start) {
	d[start] = 0; // �ڱ� �ڽ��̹Ƿ�
	priority_queue<pair<int, int>> pq; // (�ִ�)�� ����.
	pq.push(make_pair(start, 0));
	//����� ������� ó���ϹǷ� ť�� ���
	while (!pq.empty()) {
		int current = pq.top().first; 
		//ª�� ���� ���� ������ ����ȭ(-)�մϴ�.
		//�켱���� ť�� ���� ū ���� top�� ��ġ�ϹǷ� 
		//�̹� ����ȭ�� �Ͽ� ����Ǿ��ִٰ� ����
		int distance = -pq.top().second;
		//����� ��µ� 
		//printf("%d ", distance);
		//printf("\n");
		//���� ����� ���� ��尡 ���������� ���� ū������ ť�� ����
		//ť�� �ֻ�ܿ� ���� ����� ���� ��尡 ������� ��
		pq.pop();
		//�ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//���õ� ����� ���� ���
			int next = a[current][i].first;
			//���õ� ��带 ���� ���� ���ļ� ���� ���
			//���õ� ������ ���� �ּҺ�� + ���õ� ��带 ���ļ� �������� ���� ���
			//��� ���ϱ� ��� 
			int nextDistance = distance + a[current][i].second;
			//printf("%d ", nextDistance);
			//������ �ּ� ��뺸�� �� �����ϸ� ��ü�մϴ�.
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
	//�⺻������ ������� ���� ��� ����� ����
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

	//����� ����մϴ�.
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}