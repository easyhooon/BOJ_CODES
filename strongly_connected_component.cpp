#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1001

using namespace std;

int id; 
int d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>>SCC;
stack<int> s;

//DFS�� �� ������ ������ŭ ����˴ϴ�.
int dfs(int x) {
	d[x] = x; // ��帶�� ������ ��ȣ�� �Ҵ� (�ڱ��ڽ��� �θ�)
	s.push(x); // ���ÿ� �ڱ� �ڽ��� ����

	int parent = d[x];
	//������ ��带 �ϳ��� Ȯ��
	for (int i = 0; i < a[x].size(); i++) {
		//y -> ������ ��� 
		int y = a[x][i];
		//�湮���� ���� �̿� -> �ش� ���� dfs�� ����
		if (d[y] == 0) parent = min(parent, dfs(y));
		//�湮�� �Ͽ��µ� ó������ �̿�(dfs�� �������� �̿�)
		//parent���� ó���ǰ� �ִ� ���� ��
		else if (!finished[y]) parent = min(parent, d[y]);
	}
	//�θ��尡 �ڱ� �ڽ��� ���
	if (parent == d[x]) {
		//scc ��ü ����
		//�ڱ� �ڽ��� ���ö����� ����
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			//�ڱ��ڽ� (�θ��� ���°��)�� ���� ���
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	//�ڽ��� �θ� ���� ��ȯ
	return parent;
}

int main(void) {
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	printf("SCC�� ����: %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("%d��° SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}