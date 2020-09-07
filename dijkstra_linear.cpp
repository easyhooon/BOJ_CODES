#include <iostream>

using namespace std;

int number = 6;
//int INF = 10000000;
//그냥 100으로 

int a[6][6] = {
	//{0,2,5,1,INF,INF},
	{0, 2, 5, 1, 100, 100},
	{2, 0, 3, 2, 100, 100},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, 100},
	{100, 100, 1, 1, 0 ,2},
	{100, 100, 5, 100, 2, 0},
};

bool v[6]; // 방문한 노드
int d[6]; // 거리

//가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
	int min = 100; // INF 
	int index = 0;
	for (int i = 0; i < number; i++) {
		//min값보다 작고 방문하지 않았을때
		if (d[i] < min && !v[i]) { 
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
	    //시작점 부터 모든 경로의 거리를 담아둠
		d[i] = a[start][i];
	}
	v[start] = true;
	//반복문 전에 시작점을 표시했고, 마지막 노드는 방문하지않아도 최단거리는 갱신 됨
	//따라서 number(정점의 개수)-2 
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
}