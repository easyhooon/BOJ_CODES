#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11 //전체 노드의 갯수는 2^10개 이하입니다.

using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

//바로 윗 부모와 연결하는 함수입니다.
void dfs(int x, int depth) {
	c[x] = true;
	d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
	}
}

//전체 부모 관례를 설정하는 함수입니다.
void setParent() {
	dfs(0, 0); // 루트를 0으로 설정합니다.
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

//최소 공통 조상을 찾는 함수입니다.
int LCA(int x, int y) {
	//y가 더 깊도록 설정합니다.
	if (d[x] > d[y]) {
		swap(x, y);
	}
	
	//두 노드의 깊이를 동일하도록 맞춥니다.
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	//부모가 같은 경우 반환합니다.
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		//조상을 향해 거슬러 올라갑니다.
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	//바로 부모가 찾고자 하는 조상입니다.
	return parent[x][0];
}

int main(void) {
	n = 21;
	// 0과 1을 연결합니다.
	a[0].push_back(1);
	a[1].push_back(0);

	a[0].push_back(2);
	a[2].push_back(0);

	a[1].push_back(3);
	a[3].push_back(1);

	a[1].push_back(4);
	a[4].push_back(1);
	
	a[2].push_back(6);
	a[6].push_back(2);

	a[3].push_back(7);
	a[7].push_back(3);
	
	a[3].push_back(8);
	a[8].push_back(3);

	a[4].push_back(9);
	a[9].push_back(4);

	a[4].push_back(10);
	a[10].push_back(4);

	a[4].push_back(11);
	a[11].push_back(4);

	a[8].push_back(12);
	a[12].push_back(8);

	a[8].push_back(13);
	a[13].push_back(8);

	a[9].push_back(14);
	a[14].push_back(9);

	a[10].push_back(15);
	a[15].push_back(10);

	a[13].push_back(16);
	a[16].push_back(13);

	a[13].push_back(17);
	a[17].push_back(13);

	a[14].push_back(18);
	a[18].push_back(14);

	a[15].push_back(19);
	a[19].push_back(15);

	a[17].push_back(20);
	a[20].push_back(17);
	setParent();

	cout << "5와 7의 LCA: " << LCA(5, 7) << '\n';
	cout << "15와 20의 LCA: " << LCA(15, 20) << '\n';
	cout << "16와 17의 LCA: " << LCA(16, 17) << '\n';
	cout << "10와 9의 LCA: " << LCA(10, 9) << '\n';
	cout << "3와 17의 LCA: " << LCA(3, 17) << '\n';
	return 0;
}