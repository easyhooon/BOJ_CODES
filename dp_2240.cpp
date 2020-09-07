#include <bits/stdc++.h>
using namespace std;

int a[1011];
int d[3][1011][33]; //[자두나무위치][떨어지는 시간][최대로 움직일 수 있는 횟수]

//세개의 키워드 이므로 3차원으로!
//자두가 떨어지는 t초 , 최대 움직일 수 있는 W번, 자두가 위치할 수 있는 위치번호 1, 2번\
//그대로 받는 것과 움직여서 받는 것의 대소를 비교  
//1-> 1번 나무 2-> 2번나무
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w, ans;

	cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}


	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= w+1; j++) { //움직인 횟수 안움직이는 0도있으므로 + 1 !
			//공식
			//안 움직여도 자두를 먹을 수 있으므로 제한 조건 x 
			if (a[i] == 1) {
				d[1][i][j] = max(d[1][i - 1][j] + 1, d[2][i - 1][j - 1] + 1);
				d[2][i][j] = max(d[1][i - 1][j - 1], d[2][i - 1][j]);

			}
			else {
				if (i == 1 && j == 1) continue;
				//j = 1 -> 최대 움직이는 경우의수 1 -> 움직이지 않는다는 수 1개 
				//따라서  j = 2 부터 자두를 먹을 수 있음 
				d[1][i][j] = max(d[1][i - 1][j], d[2][i - 1][j - 1]);
				d[2][i][j] = max(d[1][i - 1][j - 1] + 1, d[2][i - 1][j] + 1);
			}
		}
	}

	ans = 0;

	for (int i = 1; i <= w + 1; i++) {
		//최대 움직임 ~이하 처리 방법 
		if (ans < max(d[1][t][i], d[2][t][i]))
			ans = max(d[1][t][i], d[2][t][i]);
	}

	cout << ans << '\n';

	return 0;
}