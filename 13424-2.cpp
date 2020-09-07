#include<bits/stdc++.h>

using namespace std;
#define MAX_SIZE 101
#define INF 987654321

int A[MAX_SIZE]; //���ӿ� �����ϴ� ģ����
int link[MAX_SIZE][MAX_SIZE];

int main(void) {


	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, m, a, b, c, k;

	cin >> T;
	while (T--) {

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (i == j) link[i][j] = 0;
				else link[i][j] = INF;
			}
		}

		for (int i = 0; i < m; i++) {

			cin >> a >> b >> c;
			link[a][b] = c;
			link[b][a] = c;
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> A[i];
		}

		//�����̵�
		//for (int k = 1; k <= n; k++) {
		//	for (int i = 1; i <= n; i++) {
		//		for (int j = 1; j <= n; j++) {

		//			if (i == j || i == k || j == k) continue;
		//			if (link[i][j] > link[i][k] + link[k][j]) {
		//				link[i][j] = link[i][k] + link[k][j];
		//			}
		//		}
		//	}
		//}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					//1->1 �̷��� ������ 0�̶�
					//if (i == j)
					//	continue;
					if (i == j || i == k || j == k) continue;
					else if (link[i][k] && link[k][j])
						//��ΰ� �����Ѵٸ� true �ƴϸ� false
					{
						if (link[i][j] == 0)
							//�ѹ��� ������ ������带 ���� Ž���� �����Ҷ�
							link[i][j] = link[i][k] + link[k][j];

						else
							//�ٽ�! �� ���� ��η� ����
							link[i][j] = min(link[i][j], link[i][k] + link[k][j]);

					}
				}


		int min_dis = INF;
		int min_room, sum_dis;

		for (int i = 1; i <= n; i++) { //�� ��ȣ

			sum_dis = 0;
			for (int j = 0; j < k; j++) {//���� ���� ģ����
				sum_dis += link[i][A[j]];
			}

			if (sum_dis < min_dis) {
				min_dis = sum_dis;
				min_room = i;
			}
		}

		cout << min_room << '\n';
	}

	return 0;
}
