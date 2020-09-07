#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //checked -> �湮�� �Ͽ���.
vector<int> a[8]; //8���� ���Ͱ� �� �� �ִ� �迭(�� ����� �ε����� 1���� ó��)

void dfs(int x) {
	//����Լ� ��ü�� ��ǻ�� ������ ���������ӿ� �������� ���̴� ����
	if (c[x]) return; //�湮�ߴٸ� ����
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y); //���α׷��� ��ȸ���� ���ô�� ��͸� ���� ����� 
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
	dfs(1);
	return 0;
}