#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int n = a.length(), sum = 0;
	for (int i = 0; i < n; i++) {
		//������ ��츸 ����
		if (a[i] - '0' <= 0 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	//���̰� ª�� �ܾ ����
	if (a.length() !=b.length()) {
		return a.length() < b.length();
	}
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// ���ڿ� ���Ե� ������ ������ ����
		if (aSum != bSum) {
			//���� ���� ��
			return aSum < bSum;
		}
		else {
			//���� �� 
			return a < b;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		//������ �ܾ�� �н��ϰ� ���
		if (i > 0 && a[i] == a[i - 1]) continue;
		cout << a[i] << '\n';
	}
	return 0;
}