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

	//전체를 쓸때 전체 -1(가장 용량작은거 쓸대) -2 .... 1개쓸때 중에 제일 큰거
	for (int i = n; i > 0; i--) {
		result[n - i] = v[n - i] * i;
	}
	sort(result, result + n);
	printf("%d\n", result[n-1]);
}