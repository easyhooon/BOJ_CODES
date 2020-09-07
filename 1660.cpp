#include <bits/stdc++.h>

using namespace std;
int n, cnt;
int tetra[123];

int calculate(int n){
	int k = 1;
	int j = 1;
	int i = 2;
	int index;
	while (true) {
		if (k == 1) tetra[1] = k;
		k = k + ((j + 1) * (j + 2)) / 2;
		if (k > n) {
			index = i - 1;
			break;
		}
		tetra[i] = k;
		j++;
		i++;
	}

	return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int index;
	int cnt = 0;
	cin >> n;

	index = calculate(n);
	cout << index << '\n';
	while (index > 0) {
		cnt += n / tetra[index];
		n = n % tetra[index];
		index--;
	}

	cout << cnt << '\n';

	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int tetra[123];
int dp[300001]; //입력받은 수의 최소 사면체 수 

int main() {
	int i, n, index;

	cin >> n;

	for (i = 1; tetra[i - 1] < n; i++) 
		tetra[i] = tetra[i - 1] + i * (i + 1) / 2;

	index = i - 1; //tetra배열의 크기 

	fill(dp + 1, dp + n + 1, 987654321); //임의의 큰 값으로 dp 배열을 채움

	for (int k = 0; k <= index; k++) dp[tetra[k]] = 1; //dp배열내의 해당 tetra배열 수에 해당하는 인덱스를 1로 채움-> 1개로 채울 수 있으니까
	
	for (int i = 0; i <= index; i++) {
		for (int j = tetra[i]; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - tetra[i]] + 1); //완벽한 이해x 
			//사면체에 필요한 개수 만큼 빼주고 1 더해준거랑  기존의 인덱스의 들어있는 값과 비교 
		}
	}

	cout << dp[n];

	return 0;
}*/