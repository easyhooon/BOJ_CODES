#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //checked -> 방문을 하였다.
vector<int> a[8]; //8개의 벡터가 들어갈 수 있는 배열(각 노드의 인덱스를 1부터 처리)

void dfs(int x) {
	//재귀함수 자체가 컴퓨터 내부의 스택프레임에 차곡차곡 쌓이는 형태
	if (c[x]) return; //방문했다면 끝냄
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y); //프로그래밍 대회에서 스택대신 재귀를 많이 사용함 
	}

}

int main(void) {
	//1과 2을 연결
	a[1].push_back(2);
	a[2].push_back(1);
	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);
	//2와 3을 연결
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