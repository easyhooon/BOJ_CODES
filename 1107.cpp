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

	if (M == 10) { //��ư�� �� ���� ���� ��
		printf("%d", abs(N - 100));
		return 0;
	}

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		use[temp] = -1;
	}

	//��ǥ �ڸ��� ���� �� �ڸ� �� ����� �ϴ� ��� ������ �߻� 
	//���� 944 7 2 3 4 5 6 7 9�� ��� 888���� 56ĭ �ö󰡾� �ּ����� �� �ڵ�� 811���� 133ĭ �ö� 
	num = to_string(N);
	for (int j = 0; j < num.size(); j++) {
		if (use[(num[j] - '0')] != -1) {
			tmp += num[j];
		}
		else {
			//-1�� �ƴ� ��(���� �� �� ��ư) �߿��� �� ���� ���� ����� �� ã�� 
			//������ �ڵ�
			int min = 9999; //������ ū ��
			int dec = 0; //�� �ڸ��� ���� ��
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

	//�࿩ tmp�� '0000'���� �� �� ������ 4������ �Է¹��� �ʰ� 0���� �Է¹޵��� ����
	for (int y = 0; y < tmp.size(); y++) {
		if (tmp[y] != '0') flag = 1;
	}

	if (flag == 0) {
		size = 1;
	}

	count = abs(N - stoi(tmp)) + size;

	//102���� �ι� �׳� ++���ִ°� �� ���� ��� ���
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
	for (int i = 0; i <= 1000000; i++) { //ä���� ���� 0 < c < 1000000
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press; // ��� �� ����(����) 
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}*/