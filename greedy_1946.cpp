#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > a;

//어떠한 면접자에게 두 분야 모두 밀리면 걸러냄 
int main(void) {
	int t;
	cin >> t;
	while (t--) { // 테스트 케이스를 전부 수행해야하므로 0 이 될때까지 (0보다 큰 정수는 모두 true)
		a.clear();
		int n, min = 100001, result = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		sort(a.begin(), a.end()); // 첫번째 원소, 즉 x를 기준으로 오름차순으로 정렬됨 
		for (int i = 0; i < n; i++) {
			if (min > a[i].second){
				min = a[i].second;
			    result++;
		    }
	    }
	    printf("%d\n" , result);
    }

     return 0;
}