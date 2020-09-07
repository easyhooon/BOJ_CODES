#include <bits/stdc++.h>

using namespace std;

long long d[201][201];
//d[i][j] = 0부터 j까지의 정수 i개를 더해서 그 합이 j가 되는 경우의 수 

//? + ? + ? + ? + … + ? + L = N
//? + ? + ? + ? + … + ? = N-L -> D[K-1][N-L]
//D[K][N] = ΣD[K-1][N-L] (0 ≤ L ≤ N)

long long mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	d[0][0] = 1LL;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= j; m++) {
				d[i][j] += d[i - 1][j - m];
				d[i][j] %= mod; //구할 때 마다 나눠줌 
			}
		}
	}
	cout << d[k][n] << '\n';

	return 0;
}