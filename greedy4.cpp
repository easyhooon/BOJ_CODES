#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int result[100001];

void print(vector<int> &v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


int main(void) {
	int n, k;
	int count = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	
	sort(v.begin(), v.end());

	//��ü�� ���� ��ü -1(���� �뷮������ ����) -2 .... 1������ �߿� ���� ū��
	for (int i = n; i > 0; i--) {
		result[n - i] = v[n - i] * i;
	}
	sort(result, result + n);
	printf("%d\n", result[n-1]);
}