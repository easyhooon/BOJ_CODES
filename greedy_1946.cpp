#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > a;

//��� �����ڿ��� �� �о� ��� �и��� �ɷ��� 
int main(void) {
	int t;
	cin >> t;
	while (t--) { // �׽�Ʈ ���̽��� ���� �����ؾ��ϹǷ� 0 �� �ɶ����� (0���� ū ������ ��� true)
		a.clear();
		int n, min = 100001, result = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		sort(a.begin(), a.end()); // ù��° ����, �� x�� �������� ������������ ���ĵ� 
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