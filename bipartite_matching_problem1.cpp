#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX]; //�����ϰ� �ִ� ����� ������ �迭
bool c[MAX]; // ó�� �Ǵ�

int n, m;

//��Ī�� ������ ��� True , ������ ��� False
bool dfs(int x) {
	//����� ��� ��忡 ���ؼ� �� �� �ִ��� �õ�
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//�̹� ó���� ���� ���̻� �� �ʿ䰡 ����
		if (c[t]) continue;
		c[t] = true;
		//����ְų� ���� ��忡 �� �� ������ �ִ� ���
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	//�ѹ��� �Է��� �ް� �ϴ� ���
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++ ) { //�ִ��� ��� �ֽ��ϴ�.
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << '\n';
	return 0;
}