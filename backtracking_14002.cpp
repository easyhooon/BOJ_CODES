/*#include <bits/stdc++.h>

using namespace std;

int a[1000];
int d[1000];
int v[1000];

void go(int p) {
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p]);
	//함수가 종료되면서 아래의 출력문이 실행됨 
	cout << a[p] << ' ';
	//함수의 끝. 종료되면서(앞 함수의 (go(v[p])가 실행완료) 그래서 그 아래 문장인 cout<<a[p] <<' '; 출력 
	// 반복(cout 종료 (함수종료-> go(v[p])종료 한 줄 내려옴 cout 실행) 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	int ans = d[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}
	cout << ans << '\n';
	go(p);
	cout << '\n';

	return 0;
}
*/