#include <bits/stdc++.h>

using namespace std;

int use[11];

int main()
{
	int N, M;
	string num;
	string tmp = "";

	scanf("%d", &N);

	scanf("%d", &M);

	if (M == 10) { //버튼이 다 고장 났을 때
		printf("%d", abs(N - 100));
		return 0;
	}

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		use[temp] = -1;
	}

	//목표 자릿수 보다 한 자리 더 적어야 하는 경우 문제가 발생 
	//또한 944 7 2 3 4 5 6 7 9의 경우 888에서 56칸 올라가야 최소지만 내 코드는 811에서 133칸 올라감 
	num = to_string(N);
	for (int j = 0; j < num.size(); j++) {
		if (use[(num[j] - '0')] != -1) {
			tmp += num[j];
		}
		else {
			//-1이 아닌 수(고장 안 난 버튼) 중에서 그 수와 가장 가까운 수 찾기 
			//문제인 코드
			int min = 9999; //임의의 큰 수
			int dec = 0; //그 자리에 넣을 수
			for (int x = 0; x < 10; x++) {
				if (abs((num[j] - '0') - x) < min && use[x] != -1) {
					min = abs((num[j] - '0') - x);
					dec = x;
				}   
			}
			tmp += to_string(dec);
		}
	}
	
	int size = tmp.size();
	int flag = 0;
	int count = 0;

	//행여 tmp의 '0000'같은 수 가 들어갔을때 4번으로 입력받지 않고 0으로 입력받도록 조정
	for (int y = 0; y < tmp.size(); y++) {
		if (tmp[y] != '0') flag = 1;
	}

	if (flag == 0) {
		size = 1;
	}

	count = abs(N - stoi(tmp)) + size;

	//102같이 두번 그냥 ++해주는게 더 빠를 경우 고려
	if (count < abs(N - 100)) {
		printf("%d", count);
	}
	else {
		printf("%d", abs(N - 100));
	}

	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;
bool broken[10];
int possible(int c) {
	if (c == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}
	for (int i = 0; i <= 1000000; i++) { //채널의 범위 0 < c < 1000000
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press; // 계속 더 해줌(갱신) 
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}*/