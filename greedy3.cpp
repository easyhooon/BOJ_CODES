#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

void print(vector<int> &v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	int n, k;
	int result = 0;
	int count = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	print(v, n);

	sort(v.begin(), v.end());
	print(v, n);
	while (count < n+1) {
		for (int i = 0; i < count; i++) {
			result += v[i];
		}
		count++;
	}
	printf("%d\n",result);
	// 
}