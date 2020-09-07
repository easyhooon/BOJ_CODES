#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

//���� Ŭ����
class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node; // �������
		this->time = time; // �ش� ��带 ������ ���
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
//result ->��������� ��� (�Ѻ��)
vector<Edge> a[MAX]; //��߿��� ����
vector<Edge> b[MAX]; //�������� ���

void topologySort() {
	queue<int> q;
	//������ ��带 ť�� ����
	q.push(start);
	//���̻� �湮�� ��尡 ����������
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			//�ش� ����� �������� ��������� ����� �ش� ������ ���ļ� ���� ��뺸�� �۴ٸ� 
			if (result[y.node] <= y.time + result[x]) {
				//�� ū ������ ����(�Ӱ� ��δ� �� ū���� ��������)
				result[y.node] = y.time + result[x];
			}
			//���Ӱ� ������ 0�� �� ������ ť�� �����մϴ�.
			if (--inDegree[y.node] == 0)
				q.push(y.node);
		}
	}

	//����� �������մϴ�.
	int count = 0; //  �Ӱ� ��ο� ���� ��� ������ ����
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			//���� ��ο� ���ԵǴ� �������� Ȯ��
			if (result[y] - result[x.node] == x.time) {
				count++;
				//ť���� �� ������ ��� ����
				//�ε����� ���� 0�� ��쿡��
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